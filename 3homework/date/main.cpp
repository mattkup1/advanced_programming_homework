#include "MyDate.h"

// Function to get a date from the user
MyDate getDate();

// Enumerate operation code
enum OP_CODES { EXIT, SET_DATE, L_PLUS, R_PLUS, ASSIGN, GREATER, LESS, EQUALITY };

int main()
{
    int d, m, y, opCode;
    char slash;
    // Get and print initial date from user
    MyDate firstDate = getDate();
    firstDate.print();
    cout << endl;
    // Second date for later use
    MyDate tmpDate;

    do 
    {
        cout << "Enter a code: " << endl;
        cin >> opCode;
        switch(opCode)
        {
            case EXIT:
                break;
            case SET_DATE:
            // Get a new date from the user and set the initial date to the new date
                cout << "Enter a date" << endl;
                cin >> d >> slash >> m >> slash >> y;
                firstDate.setDate(d, m, y);
                firstDate.print();
                cout << endl;
                break;
            case L_PLUS:
            // Print the result of a left side '++' on the initial date
                tmpDate = ++firstDate;
                tmpDate.print();
                cout << endl;
                firstDate.print();
                cout << endl;
                break;
            case R_PLUS:
            // Print the result of a right side '++' on the initial date
                tmpDate = firstDate++;
                tmpDate.print();
                cout << endl;
                firstDate.print();
                cout << endl;
                break;
            case ASSIGN:
            // Get a new date from the user and assign it to the initial date via assignment '=' operator
            // Print the newly assigned date
                firstDate = getDate();
                firstDate.print();
                cout << endl;
                break;
            case GREATER:
            // Get new date from user and check if it is earlier than the initial date
                tmpDate = getDate();
                firstDate.print();
                cout << " < ";
                tmpDate.print();
                cout << " : ";
                cout << (firstDate > tmpDate ? "true" : "false") << endl;
                break;
            case LESS:
            // Get a new date from the user and check if it is later than the initial date
                tmpDate = getDate();
                firstDate.print();
                cout << " < ";
                tmpDate.print();
                cout << " : ";
                cout << (firstDate < tmpDate ? "true" : "false") << endl;
                break;
            case EQUALITY:
            // Get a new date from the user and check if it is equal to the initial date
                tmpDate = getDate();
                firstDate.print();
                cout << " == ";
                tmpDate.print();
                cout << " : ";
                cout << (firstDate == tmpDate ? "true" : "false") << endl;
                break;
        }
    } while (opCode != EXIT);

    return 0;
}


MyDate getDate()
{
    int d, m, y;
    char slash;

    // Get user input
    cout << "Enter a date: " << endl;
    cin >> ws;
    cin >> d >> slash >> m >> slash >> y;
    // Create a new date with user input
    MyDate tmp(d, m, y);
    // Return the new date
    return tmp;
}