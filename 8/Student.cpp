/*
    Student.cpp:
    Implementation file for the abstract Student class.
    This file provides the definitions for the Student class's constructors,
    copy constructor, and virtual methods for printing and inputting student information.
    The Student class serves as a base for all student types (BA, MA, PHD) in the university system.
*/

#include "Student.h"


// Default constructor
// Initializes a Student object with the given id, first name, last name, and number of courses.
Student::Student(int id_, string fn, string ln, int numCourses)
    : id(id_), firstName(fn), lastName(ln), numberOfCourses(numCourses)
{}

// Copy constructor
// Initializes a Student object as a copy of another Student object.
Student::Student(const Student& src)
    : id(src.id), firstName(src.firstName), lastName(src.lastName),
      numberOfCourses(src.numberOfCourses)
{}


// Prints student information and scholarship eligibility.
// If the student is eligible for a scholarship, prints a special message.
void Student::print() const
{
    // Check if student is eligible for scholarship and print accordingly
    if (this->milga())
        cout << "*** Scholarship ***" << endl;
    
    cout << "ID: " << this->id << endl
         << "Name: " << this->firstName << " "
         << this->lastName << endl;
}

// Prompts the user to enter student information and reads it from standard input.
void Student::input()
{
    cout << "enter id, first name, last name, number of courses" << endl;
    cin >> this->id >> this->firstName >> this->lastName >> this->numberOfCourses;
}