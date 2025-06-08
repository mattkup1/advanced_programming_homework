#include "BA.h"


// Default ctor
BA::BA(int id, string fn, string ln, int numCourses)
    : Student::Student(id, fn, ln, numCourses),
      grades(new int[numCourses])
{}


// Copy ctor
BA::BA(const BA& src)
    : Student(src), grades(new int[src.numberOfCourses])
{
    for (int i = 0; i < this->numberOfCourses; ++i)
        this->grades[i] = src.grades[i];
}


// Move ctor
BA::BA(BA&& src) : Student(src), grades(src.grades)
{
    src.grades = nullptr;
}


// Assignment operator
BA& BA::operator=(const BA& src)
{
    if (this == &src)
        return *this;
    
    this->id = src.id;
    this->firstName = src.firstName;
    this->lastName = src.lastName;
    this->numberOfCourses = src.numberOfCourses;

    if (this->grades)
        delete [] this->grades;
    this->grades = new int[this->numberOfCourses];
    for (int i = 0; i < this->numberOfCourses; ++i)
        this->grades[i] = src.grades[i];
    
    return *this;
}


// Move assignment
BA& BA::operator=(BA&& src)
{
    if (this == &src)
        return *this;
    
    this->id = src.id;
    this->firstName = src.firstName;
    this->lastName = src.lastName;
    this->numberOfCourses = src.numberOfCourses;
    if (this->grades)
        delete [] this->grades;
    this->grades = src.grades;
    return *this;
}


// Method to compute whether the student is eligible for scholarship
// For BA: Signed up for at least 10 courses and has GPA over 95
bool BA::milga() const
{
    if (this->numberOfCourses < 10)
        return false;

    int gradeSum = 0;
    for (int i = 0; i < this->numberOfCourses; ++i)
        gradeSum += this->grades[i];

    return (gradeSum / this->numberOfCourses) > 95;
}


// Method to print student information and scholarship elegibility
void BA::print() const
{
    // First call parent method
    this->Student::print();
    // Print BA specifics
    cout << "grades: ";
    for (int i = 0; i < this->numberOfCourses; ++i)
        cout << this->grades[i] << " ";
    cout << endl;
}


// Method to get student information from the user
void BA::input()
{
    // Call parent method to get input to global fields
    this->Student::input();
    // Get BA specific input
    cout << "enter a list of student grades: " << endl;
    for (int i = 0; i < this->numberOfCourses; ++i)
        cin >> this->grades[i];
}