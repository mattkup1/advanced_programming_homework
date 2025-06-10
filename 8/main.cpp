#include "BA.h"
#include "MA.h"
#include "PHD.h"

// Function to read students from user to an array of students
void addStudent(Student** arr);

enum OPTIONS{ EXIT, BA_STUDENT, MA_STUDENT, PHD_STUDENT };


int main()
{
    // Declare a dynamic array for students of all types
    Student** students;
    // Get number of students from the user
    int numStudents;
    cout << "enter number of students: " << endl;
    cin >> numStudents;
    // Allocate memory for the students dynamic array
    students = new Student*[numStudents];

    // Use function to read students from user to array
    // Function relies on user cooperation 
    // User must enter 0 at the prompt once the number of students in the array reaches the array's capacity
    addStudent(students);
    
    // Print all scholarship eligible students
    cout << endl << "list of students with a scholarship:" << endl << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        // Print only students who are eligible for a scholarship
        if (students[i]->milga())
        {
            // Print student type and student's information
            cout << students[i]->studType() << endl;
            students[i]->print();
        }
    }   

    // Print all non scholarship eligible students
    cout << "list of students without a scholarship: " << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        // Print only students who are NOT eligible for a scholarship
        if (!students[i]->milga())
        {
            // Print student type and student's information
            cout << students[i]->studType() << endl;
            students[i]->print();
        }
        // Dealocate current student memory
        delete students[i];
    }

    // Dealocate array memory
    delete [] students;

    return 0;
}


void addStudent(Student** arr)
{ 
    int choice, i = 0; 
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
            // Append student to students array
            arr[i++] = s; 
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

enter number of students: 
5
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1   
enter id, first name, last name, number of courses
111 Mark Zuckerberg 10
enter a list of student grades
98 95 94 96 97 93 100 99 98 98
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
2
enter id, first name, last name, number of courses
222 Elon Musk 8
enter a list of student grades
99 98 99 97 97 100 99 100
research? enter Y or N
Y
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
3
enter id, first name, last name, number of courses
333 Adriana Rosie 3
enter number of research hours
38
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1
enter id, first name, last name, number of courses
444 Taylor Swift 10
enter a list of student grades
96 95 94 93 92 91 92 92 97 82
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
2
enter id, first name, last name, number of courses
555 Benson Boon 3
enter a list of student grades
100 99 99
research? enter Y or N
Y
enter 0 to exit
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
0
list of students with a scholarship: 
BA student
*** Scholarship ***
ID: 111
Name: Mark Zuckerberg
grades: 98 95 94 96 97 93 100 99 98 98 
MA student
*** Scholarship ***
ID: 222
Name: Elon Musk
grades: 99 98 99 97 97 100 99 100 
research: YES
PHD student
*** Scholarship ***
ID: 333
Name: Adriana Rosie
number of research hours: 38
list of students without a scholarship: 
BA student
ID: 444
Name: Taylor Swift
grades: 96 95 94 93 92 91 92 92 97 82 
MA student
ID: 555
Name: Benson Boon
grades: 100 99 99 
research: YES
*/