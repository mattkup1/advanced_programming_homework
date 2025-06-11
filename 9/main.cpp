/*
    main.cpp:
    Program to manage a database with student information
    by using the STL list, vector, stack and queue containers
*/

#include <list>
#include <vector>
#include <stack>
#include <queue>
#include "BA.h"
#include "MA.h"
#include "PHD.h"

// Function to read students from user to a linked list of students
void addStudent(list<Student*>&);

enum OPTIONS{ EXIT, BA_STUDENT, MA_STUDENT, PHD_STUDENT };


int main()
{
    // Declare STL containers
    list<Student*> s_list;
    vector<Student*> PHD_vector;
    vector<Student*> MA_vector;
    vector<Student*> BA_vector;
    stack<Student*> s_stack;
    queue<Student*> s_queue;

    // Use function to read students from user to array
    // User decides the number of students in the list
    addStudent(s_list);
    
    // Separate students to 3 separate vectors by student type
    // Maintain inserted order in ascending order
    while (!s_list.empty())
    {
        Student* s = s_list.front();

        // Insert each student to appropriate container
        if (s->studType() == "PHD")
            PHD_vector.push_back(s);
        else if (s->studType() == "MA")
            MA_vector.push_back(s);
        else
            BA_vector.push_back(s);
        
        // Remove current studnet from list
        s_list.pop_front();
    }

    // Transfer all students from vectors to 
    // a Queue to print in FIFO order
    // Vector transfer order (L-R): BA, MA, PHD
    for (Student* s : BA_vector)
        s_queue.push(s);
    for (Student* s : MA_vector)
        s_queue.push(s);
    for (Student* s : PHD_vector)
        s_queue.push(s);
    
    cout << "\n\n\n\nlist of students with a scholarship:\n\n";

    // Print all students eligible for a scholarship in inserted order (FIFO)
    // Students not eligible for scholarship should be pushed into a stack 
    // to print in reversed order (LIFO)
    // Additionally, Deallocate memory for each printed student
    // as they will no longer be used in the program
    while (!s_queue.empty())
    {
        // Get next student from queue
        Student* s = s_queue.front();
        // Case student is eligible for scholarship - Print student info and free memory 
        if (s->milga())
        {
            s->print();
            delete s;
            s = nullptr;
        }
        // Case student not eligible for scholarship - Transfer to stack
        else
            s_stack.push(s);
        
        // Remove student from queue
        s_queue.pop();
    }

    cout << "\n\nlist of students without a scholarship\n\n";

    // Print all students from stack (LIFO)
    // once printed, Deallocate printed studnet's memory
    while (!s_stack.empty())
    {
        // Get next student from stack
        Student* s = s_stack.top();
        // Print student info and free memory
        s->print();
        delete s;
        s = nullptr;
        // Remove student from stack
        s_stack.pop();
    }

    return 0;
}


void addStudent(list <Student*>& s_list)
{  
    int choice;
    Student* s = nullptr; 

    do 
    { 
        // Prompt user for menu option
        cout << "enter 0 to exit\n"; 
        cout << "enter 1 to add a BA student\n"; 
        cout << "enter 2 to add a MA student\n"; 
        cout << "enter 3 to add a PHD student\n"; 
        cin >> choice; 
        
        try 
        { 
            switch (choice) 
            { case EXIT: 
                    return; 
                case BA_STUDENT:
                    s = new BA(); 
                        break; 
                case MA_STUDENT: 
                    s = new MA(); 
                    break; 
                case PHD_STUDENT: 
                    s = new PHD(); 
                    break; 
                default: 
                    throw "Exception: no such degree\n"; 
            } 
            // Read student information from user
            s->input(); 
            // Insert student to the end of the list
            s_list.push_back(s);
        } 
        // Handle invalid input
        catch (const char* message) 
        { 
            cout << message; 
        } 

    } while (choice != 0);  // Break on exit option
}

/*
EXAMPLE:

enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
2
enter id, first name, last name, number of courses
111 Jason Mamoa 6
enter a list of student grades
90 91 92 93 94 95
research? enter Y or N
Y
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
3
enter id, first name, last name, number of courses
222 Travis Kelce 3
enter number of research hours
28       
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1
enter id, first name, last name, number of courses
333 Tom Brady 9
enter a list of student grades
86 90 67 99 100 100 95 93 92   
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
3
enter id, first name, last name, number of courses
444 Huge Jackman 3
enter number of research hours
29
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
2
enter id, first name, last name, number of courses
555 Andy Samberg 8
enter a list of student grades
95 96 94 99 100 99 99 99
research? enter Y or N
Y
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1
enter id, first name, last name, number of courses
666 Sydney Sweenie 10
enter a list of student grades
100 99 99 99 96 92 93 99 99 99 99 
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
Exception: no such degree
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
0




list of students with a scholarship:

*** Scholarship ***
ID: 666
Name: Sydney Sweenie
grades: 100 99 99 99 96 92 93 99 99 99 
*** Scholarship ***
ID: 555
Name: Andy Samberg
grades: 95 96 94 99 100 99 99 99 
research: YES
*** Scholarship ***
ID: 222
Name: Travis Kelce
number of research hours: 28
*** Scholarship ***
ID: 444
Name: Huge Jackman
number of research hours: 29


list of students without a scholarship

ID: 111
Name: Jason Mamoa
grades: 90 91 92 93 94 95 
research: YES
ID: 333
Name: Tom Brady
grades: 86 90 67 99 100 100 95 93 92 
*/