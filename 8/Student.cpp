#include "Student.h"


// Default ctor
Student::Student(int id_, string fn, string ln, int numCourses)
    : id(id_), firstName(fn), lastName(ln), numberOfCourses(numCourses)
{}

// Copy ctor
Student::Student(const Student& src)
    : id(src.id), firstName(src.firstName), lastName(src.lastName),
      numberOfCourses(src.numberOfCourses)
{}


// Method to print student information and scholarship elegibility
void Student::print() const
{
    if (this->milga())
        cout << "*** Scholarship ***" << endl;
    
    cout << "ID: " << this->id << endl
         << "Name: " << this->firstName << " "
         << this->lastName << endl;
}


// Method to get student information from the user
void Student::input()
{
    cout << "enter id, first name, last name, number of courses" << endl;
    cin >> this->id >> this->firstName >> this->lastName >> this->numberOfCourses;
}