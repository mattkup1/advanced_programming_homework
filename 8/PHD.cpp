#include "PHD.h"


// Default ctor
PHD::PHD(int id, string fn, string ln, int numCourses, int hrs) 
    : Student(id, fn, ln, numCourses), weeklyResearchHrs(hrs)
{}


// Copy ctor
PHD::PHD(const PHD& src) : Student(src)
{
    this->weeklyResearchHrs = src.weeklyResearchHrs;
}


// Move ctor
PHD::PHD(PHD&& src) : Student(src)
{
    this->weeklyResearchHrs = src.weeklyResearchHrs;
}


// Copy assignment
PHD& PHD::operator=(const PHD& src)
{
    if (this == &src)
        return *this;
    Student::operator=(src);
    this->weeklyResearchHrs = src.weeklyResearchHrs;
}


// Move assignment
PHD& PHD::operator=(PHD&& src)
{
    if (this == &src)
        return *this;
    Student::operator=(src);
    this->weeklyResearchHrs = src.weeklyResearchHrs;
}


// Method to compute whether the student is eligible for scholarship
// For PHD: Signed up for at least 2 courses and engages in at least 25 weekly research hours
bool PHD::milga() const
{
    return (this->numberOfCourses >= 2 && this->weeklyResearchHrs >= 25);
}


// Method to print student information and scholarship elegibility
void PHD::print() const
{
    Student::print();
    cout << "number of research hours: " << this->weeklyResearchHrs;
}


// Method to get student information from the user
void PHD::input()
{
    Student::input();
    cout << "enter number of research hours" << endl;
    cin >> this->weeklyResearchHrs;
}