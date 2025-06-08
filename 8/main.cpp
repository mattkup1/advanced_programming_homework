#include "BA.h"
#include "MA.h"
#include "PHD.h"

enum choice{ EXIT, BA_STUDENT, MA_STUDENT, PHD_STUDENT };


int main()
{

    return 0;
}


void addStudent(Student** arr)
{ 
    int choice, i = 0;
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

            s->input(); arr[i++] = s; 
        } 

        catch (const char* message) 
        { 
            cout << message; 
        } 

    } while (choice != 0);