#include "BA.h"
#include "MA.h"
#include "PHD.h"

void addStudent(Student** arr, int index);

enum OPTIONS{ EXIT, BA_STUDENT, MA_STUDENT, PHD_STUDENT };


int main()
{
    Student** students;
    int numStudents;
    cout << "enter number of students: " << endl;
    cin >> numStudents;
    students = new Student*[numStudents];

    for (int i = 0; i < numStudents; ++i)
        addStudent(students, i);
    
    // Print all scholarship eligible students
    cout << "list of students with a scholarship: " << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        if (students[i]->milga())
        {
            cout << students[i]->studType() << endl;
            students[i]->print();
        }
    }   

    // Print all non scholarship eligible students
    cout << "list of students without a scholarship: " << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        if (!students[i]->milga())
        {
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


void addStudent(Student** arr, int index)
{ 
    int choice;
    Student* s = nullptr;
    cout << "enter 0 to exit\n";
    cout << "enter 1 to add a BA student\n";
    cout << "enter 2 to add a MA student\n";
    cout << "enter 3 to add a PHD student\n";
    cin >> choice; 

    try 
    { 
        switch (choice) 
        { 
            case EXIT: 
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
        s->input(); 
        arr[index] = s; 
    } 

    catch (const char* message) 
    { 
        cout << message; 
    } 
}