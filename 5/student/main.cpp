#include "Registration.h"  
using namespace std;

enum Choices {
    END,ADD,DELETE,UPDATE,CHECK,PRINT,PRINTALL
};
int enterChoice() {
    cout << "\nenter your choice:" << endl;
    cout << "0 - to end the program" << endl;
    cout << "1 - to register a new student" << endl;
    cout << "2 - to delete a student from the file" << endl;
    cout << "3 - update a student\'s registration" << endl;
    cout << "4 - check if a student is registered for a course" << endl;
    cout << "5 - print a student\'s details" << endl;
    cout << "6 - print all of the students\' details "<<endl;
    int menuChoice;
    do
        cin >> menuChoice;
    while (menuChoice<END || menuChoice>PRINTALL);
    return menuChoice;
   
}

int main() {
    Registration file("registration.dat");
    int choice;
    while ((choice = enterChoice()) != END) {
        switch (choice) {
        case ADD: file.addStudent();
            break;
        case DELETE:file.deleteStudent();
            break;
        case UPDATE:file.update();
            break;
        case CHECK:file.checkRegistered();
                    break;
        case PRINT:file.printStudent();
            break;
        case PRINTALL:file.printAll();
            break;
        }
    }
    return 0;
}

/*
EXAMPLE:

*/