#include "BA.h"


// Default ctor
BA::BA(int id, string fn, string ln, int numCourses)
    : Student(id, fn, ln, numCourses)
{
    if (this->numberOfCourses > 0)
        this->grades = new int[this->numberOfCourses];
    else
        this->grades = nullptr;
}


// Copy ctor
BA::BA(const BA& src)
    : Student(src)
{
    if (this->numberOfCourses > 0)
    {
        this->grades = new int[this->numberOfCourses];
        for (int i = 0; i < this->numberOfCourses; ++i)
            this->grades[i] = src.grades[i];
    }
    else
        this->grades = nullptr;
}


// Move ctor
BA::BA(BA&& src) : Student(src), grades(src.grades)
{
    src.grades = nullptr;
}


// dtor
BA::~BA()
{
    if (this->grades)
        delete [] this->grades;
    this->grades = nullptr;
    this->numberOfCourses = 0;
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
    src.grades = nullptr;
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

    return (gradeSum / this->numberOfCourses) >= 95;
}


// Method to print student information and scholarship elegibility
void BA::print() const
{
    // First call parent method to print global student information
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
    if (this->grades)
        delete [] this->grades;
    // Call parent method to get input to global fields
    this->Student::input();
    this->grades = new int[numberOfCourses];
    // Get BA specific input
    cout << "enter a list of student grades" << endl;
    for (int i = 0; i < this->numberOfCourses; ++i)
        cin >> this->grades[i];
}