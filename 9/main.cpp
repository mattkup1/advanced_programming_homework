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
    
    // TODO: Separate students to 3 separate vectors by student type
    // Maintain inserted order in ascending order

    // TODO: Transfer all students from vectors to 
    // a Queue to print in FIFO order
    // Vector transfer order (L-R): PHD, MA, BA

    cout << "list of students without a scholarship: " << endl;

    // TODO: Print all students eligible for a scholarship in dequeued order
    // Students not eligible for scholarship should be pushed into a stack 
    // to print in reversed order (LIFO)
    // Additionally, Deallocate memory for each printed student
    // as they will no longer be used in the program

    // TODO: Print all students from stack in popped order (LIFO)
    // once printed, Deallocate printed studnet's memory

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

*/