#include "BA.h"
#include "MA.h"
#include "PHD.h"

void addStudent(Student** arr, int pos);

enum choice{ EXIT, BA_STUDENT, MA_STUDENT, PHD_STUDENT };


int main()
{
    Student** students;
    int numStudents;
    cout << "enter number of students: " << endl;
    cin >> numStudents;
    students = new Student*[numStudents];

    int scholarshipCount = 0;

    for (int i = 0; i < numStudents; ++i)
        addStudent(students, i);

    
    
    for (int i = 0; i < numStudents; ++i)
        // TODO: print students that get scholarships
    for (int i = 0; i < numStudents; ++i)
        // TODO: print students that DO NOT get scholarships
        
    return 0;
}


void addStudent(Student** arr, int pos)
{ 
    int choice;
    Student* s = nullptr;
    
    do 
    { 
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

            s->input(); arr[pos] = s; 
        } 

        catch (const char* message) 
        { 
            cout << message; 
        } 

    } while (choice != 0);