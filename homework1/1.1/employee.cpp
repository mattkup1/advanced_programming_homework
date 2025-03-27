/*
1: Name: Matt Kuperwasser 3222667270
2: Course: Advanced Programming
3: Homework 1, Question 1
4: This file implements the Employee class, including methods for setting and getting employee details,
as well as calculating salary based on wage, work hours, and commission.
*/

#include <iostream>

#include "employee.h"

using namespace std;

// Sets the employee ID
// Ensures the ID is a five-digit number, otherwise prints an error message.
void Employee::setId(int n)
{
    if (n < 10000 || n > 99999)
    {
        cout << "ERROR" << endl;
        return;
    }
    this->id = n;
}

// Returns the employee ID
int Employee::getId() const
{
    return this->id;
}

// Sets the employee name
// Copies the input string into the name array, ensuring it does not exceed 20 characters.
void Employee::setName(const char* s)
{
    if (s == nullptr)
    {
        this->name[0] = '\0';  // Set to an empty string
    }

    size_t len = strlen(s);  // Get actual length of s
    if (len > 20) len = 20;  // Limit length to 20

    strncpy(this->name, s, len); // Copy only the actual length
    this->name[len] = '\0'; // Ensure null termination
}

// Returns a dynamically allocated copy of the employee's name
// Caller is responsible for freeing the allocated memory.
const char* Employee::getName() const
{
    return this->name;
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
    if (n >= 0)
        moneyCollected = n;
    else
        cout << "ERROR" << endl;
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
    float commission = 0;

    if (moneyCollected < 1000)        commission = 0.1;
    else if (moneyCollected < 2000)   commission = 0.15;
    else if (moneyCollected < 4000)   commission = 0.2;
    else if (moneyCollected < 5000)   commission = 0.3;
    else if (moneyCollected >= 5000)  commission = 0.4;

    return static_cast<int>((workHours * wage) + (moneyCollected * commission));
}