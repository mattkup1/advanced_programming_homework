#include "Student.h"


// Method to print student information and scholarship elegibility
void Student::print() const
{
    if (this->milga())
        cout << "Scholarship" << endl;
    
    cout << "ID: " << this->id << endl
         << "NAME: " << this->firstName << " "
         << this->lastName << endl;
}


// Method to get student information from the user
void Student::input()
{
    cout << "enter id, first name, last name, number of courses" << endl;
    cin >> this->id >> this->firstName >> this->lastName >> this->numberOfCourses;
}