#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// employee.h
// This file defines the Employee class, which stores and manages employee details,
// including ID, name, wage, work hours, and money collected.

#include <iostream>
#include <cstring>

using namespace std;

// Employee class
// Represents an employee with attributes such as ID, name, wage, work hours, and money collected.
class Employee
{
    // Private member variables - accessible only within the class
    private: 
        // Employee ID (default: 11111)
        int id = 11111;
        
        // Employee name (up to 20 characters)
        char name[21] = {'\0'};
        
        // Hourly wage of the employee
        float wage = 0.0;
        
        // Number of hours worked
        int workHours = 0;
        
        // Total money collected by the employee
        float moneyCollected = 0.0;

    // Public member functions - accessible from outside the class
    public:
        // Sets the employee ID
        void setId(int);
        // Returns the employee ID
        int getId() const;

        // Sets the employee name
        void setName(const char*);
        // Returns the employee name
        const char* getName() const;

        // Sets the hourly wage
        void setWage(float);
        // Returns the hourly wage
        float getWage() const;

        // Sets the number of work hours
        void setWorkHours(int);
        // Returns the number of work hours
        int getWorkHours() const;

        // Sets the total money collected by the employee
        void setMoneyCollected(float n);
        // Returns the total money collected by the employee
        float getMoneyCollected() const;

        // Calculates and returns the employee's salary based on wage and work hours
        int calculateSalary() const;
};

#endif // !EMPLOYEE_H