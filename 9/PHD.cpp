/*
    PHD.cpp:
    Implementation file for the PHD (Doctor of Philosophy) class, derived from the abstract Student class.
    This file defines the constructors, assignment operators, and overrides for scholarship eligibility,
    student type identification, input, and output. The class adds management of weekly research hours.
*/

#include "PHD.h"


// Default constructor
// Initializes a PHD student with optional id, name, number of courses, and research hours.
PHD::PHD(int id, string fn, string ln, int numCourses, int hrs) 
    : Student(id, fn, ln, numCourses), weeklyResearchHrs(hrs)
{}


// Copy constructor
// Creates a deep copy of another PHD student, including research hours.
PHD::PHD(const PHD& src) 
    : Student(src), weeklyResearchHrs(src.weeklyResearchHrs)
{}


// Move constructor
// Transfers resources from another PHD student, including research hours.
PHD::PHD(PHD&& src) 
    : Student(src), weeklyResearchHrs(src.weeklyResearchHrs)
{}


// Copy assignment operator
// Assigns another PHD student to this one (deep copy of research hours).
PHD& PHD::operator=(const PHD& src)
{
    // Handle self-assignment
    if (this == &src)
        return *this;
    // Copy base class members
    Student::operator=(src);
    // Copy research hours
    this->weeklyResearchHrs = src.weeklyResearchHrs;
    return *this;
}


// Move assignment operator
// Moves another PHD student's resources to this one, including research hours.
PHD& PHD::operator=(PHD&& src)
{
    // Handle self-assignment
    if (this == &src)
        return *this;
    // Move base class members
    Student::operator=(src);
    // Move research hours
    this->weeklyResearchHrs = src.weeklyResearchHrs;
    return *this;
}


// Determines if the student is eligible for a scholarship
// For PHD: Must be signed up for at least 2 courses and have at least 25 weekly research hours.
bool PHD::milga() const
{
    return (this->numberOfCourses >= 2 && this->weeklyResearchHrs >= 25);
}


// Prints student information and scholarship eligibility
void PHD::print() const
{
    // Print base student information
    Student::print();
    // Print PHD-specific information: research hours
    cout << "number of research hours: " << this->weeklyResearchHrs << endl;
}


// Reads student information and research hours from user input
void PHD::input()
{
    // Get base student information
    Student::input();
    // Get PHD-specific input: research hours
    cout << "enter number of research hours" << endl;
    cin >> this->weeklyResearchHrs;
}