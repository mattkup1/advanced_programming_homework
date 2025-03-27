/*
1: Name: Matt Kuperwasser 3222667270
2: Course: Advanced Programming
3: Homework 1, Question 1
4: This program manages employee records, allowing input of employee details,
and calculating minimum sales, highest salary, and printing employee information.
*/

#include <iostream>

#include "employee.h"

using namespace std;

// Function to print employee details
void print(Employee e);

// Function to find the index of the employee with the minimum amount sold
int minimumSold(Employee employees[]);

// Function to find the index of the employee with the highest salary
int highestSalary(Employee employees[]);

// Constant defining the number of employees
const int EMPLOYEE_COUNT = 5;

// Main function - Handles employee data input and output
int main(void)
{
    Employee employees[EMPLOYEE_COUNT];

    // Loop to input employee details
    for (int i = 0; i < EMPLOYEE_COUNT; i++)
    {
        int id;
        char name[21];
        float wage;
        int workHours;
        float moneyCollected;

        cout << "Enter details, for employee number " << i + 1 << " :" << endl;
        
        cin >> id;
        cin.ignore();
        cin >> name;
        cin >> wage;
        cin >> workHours;
        cin >> moneyCollected;

        employees[i].setId(id);
        employees[i].setName(name);
        employees[i].setWage(wage);
        employees[i].setWorkHours(workHours);
        employees[i].setMoneyCollected(moneyCollected);
    }

    cout << endl;

    // Display the employee with the minimum amount sold
    cout << "Minimum Sold: ";
    print(employees[minimumSold(employees)]);
    cout << endl;
    
    // Display the employee with the highest salary
    cout << "Highest Salary: ";
    print(employees[highestSalary(employees)]);
    cout << endl;

    // Display all employee details
    cout << "All Employees: " << endl;
    for (int i = 0; i < EMPLOYEE_COUNT; i++)
    {
        print(employees[i]);
        cout << endl;
    }

    return 0;
}

// Function to print employee details
// Displays ID, Name, Wage, Work Hours, Amount Sold, and Total Salary
void print(Employee e)
{
    cout << "ID: " << e.getId() << endl;
    cout << "Name: " << e.getName() << endl;
    cout << "Salary Per Hour: " << e.getWage() << endl;
    cout << "Hours: " << e.getWorkHours() << endl;
    cout << "Amount Sold: " << e.getMoneyCollected() << endl;
    cout << "Total Salary: " << e.calculateSalary() << endl;

    return;
}

// Function to determine which employee has the least sales
// Iterates through employees to find the minimum money collected
// Returns the index of the employee with the least amount sold
int minimumSold(Employee employees[])
{
    int min = employees[0].getMoneyCollected();
    int index = 0;

    for (int i = 1; i < EMPLOYEE_COUNT; i++)
    {
        if (employees[i].getMoneyCollected() < min)
        {
            min = employees[i].getMoneyCollected();
            index = i;
        }
    }

    return index;
}

// Function to determine which employee has the highest salary
// Iterates through employees to find the maximum salary calculated
// Returns the index of the employee with the highest salary
int highestSalary(Employee employees[])
{
    int max = employees[0].calculateSalary();
    int index = 0;

    for (int i = 1; i < EMPLOYEE_COUNT; i++)
    {
        if (employees[i].calculateSalary() > max)
        {
            max = employees[i].calculateSalary();
            index = i;
        }
    }

    return index;
}


/*
Example: 

Enter details, for employee number 1 :
12345
Matt
40
50
2500
Enter details, for employee number 2 :
23456
Moshe
30
50
500
Enter details, for employee number 3 :
34567
Avraham
50
100
1500
Enter details, for employee number 4 :
45678
Neriah
100
20
4000
Enter details, for employee number 5 :
0
Raffi
-4
-10
6000
ERROR
ERROR
ERROR

Minimum Sold: ID: 23456
Name: Moshe
Salary Per Hour: 30
Hours: 50
Amount Sold: 500
Total Salary: 1550

Highest Salary: ID: 34567
Name: Avraham
Salary Per Hour: 50
Hours: 100
Amount Sold: 1500
Total Salary: 5225

All Employees: 
ID: 12345
Name: Matt
Salary Per Hour: 40
Hours: 50
Amount Sold: 2500
Total Salary: 2500

ID: 23456
Name: Moshe
Salary Per Hour: 30
Hours: 50
Amount Sold: 500
Total Salary: 1550

ID: 34567
Name: Avraham
Salary Per Hour: 50
Hours: 100
Amount Sold: 1500
Total Salary: 5225

ID: 45678
Name: Neriah
Salary Per Hour: 100
Hours: 20
Amount Sold: 4000
Total Salary: 3200

ID: 11111
Name: Raffi
Salary Per Hour: 0
Hours: 0
Amount Sold: 6000
Total Salary: 2400
*/