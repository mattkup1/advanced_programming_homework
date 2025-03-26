#include <iostream>
#include <cstring>

// employee.cpp
// This file implements the Employee class, including methods for setting and getting employee details,
// as well as calculating salary based on wage, work hours, and commission.

#include "employee.h"

using namespace std;

// Sets the employee ID
// Ensures the ID is a five-digit number, otherwise prints an error message.
void Employee::setId(int n)
{
    if (n < 10000 or n > 99999)
        cout << "ERROR" << endl;
    else
        id = n;

    return;
}

// Returns the employee ID
int Employee::getId() const
{
    return id;
}

// Sets the employee name
// Copies the input string into the name array, ensuring it does not exceed 20 characters.
void Employee::setName(char s[])
{
    int i;
    for (i = 0; i < 20 and s[i] != '\0'; i++)
    {
        name[i] = s[i];
    }
    name[i] = '\0';

    return;
}

// Returns a dynamically allocated copy of the employee's name
// Caller is responsible for freeing the allocated memory.
char* Employee::getName() const
{
    int len = strlen(name);
    char* namePtr = new char[len + 1];
    strncpy(namePtr, name, len + 1);
    namePtr[len] = '\0';

    return namePtr;
}

// Sets the employee's hourly wage
// Ensures the wage is non-negative; otherwise, prints an error message.
void Employee::setWage(float n)
{
    (n >= 0) ? wage = n : printf("ERROR\n");

    return;
}

// Returns the employee's hourly wage
float Employee::getWage() const
{
    return wage;
}

// Sets the number of hours worked
// Ensures the value is non-negative; otherwise, prints an error message.
void Employee::setWorkHours(int n)
{
    (n >= 0) ? workHours = n : printf("ERROR\n");

    return;
}

// Returns the number of hours worked
int Employee::getWorkHours() const
{
    return workHours;
}

// Sets the total money collected by the employee
// Ensures the value is non-negative; otherwise, prints an error message.
void Employee::setMoneyCollected(float n)
{
    (n >= 0) ? moneyCollected = n : printf("ERROR\n");

    return;
}

// Returns the total money collected by the employee
float Employee::getMoneyCollected() const
{
    return moneyCollected;
}

// Calculates the employee's salary
// Base salary is calculated as wage multiplied by work hours.
// Additional commission is based on money collected:
// - < 1000: 10%
// - 1000 - 1999: 15%
// - 2000 - 3999: 20%
// - 4000 - 4999: 30%
// - 5000+: 40%
// Returns the final salary as an integer.
int Employee::calculateSalary() const
{
    float commission;

    if (moneyCollected < 1000)
        commission = 0.1;
    else if (1000 <= moneyCollected and moneyCollected < 2000)
        commission = 0.15;
    else if (2000 <= moneyCollected and moneyCollected < 4000)
        commission = 0.2;
    else if (4000 <= moneyCollected and moneyCollected < 5000)
        commission = 0.3;
    else if (moneyCollected >= 5000)
        commission = 0.4;
    else
    {
        cout << "ERROR" << endl; 
        return 0;
    }

    float salary = (workHours * wage);
    salary += (moneyCollected * commission);

    return static_cast <int> (salary);
}