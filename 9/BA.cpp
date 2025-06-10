/*
    BA.cpp

    Implementation file for the BA (Bachelor of Arts) class, derived from the abstract Student class.
    This file defines the constructors, destructor, copy/move operations, and overrides for scholarship eligibility,
    student type identification, input, and output. The class manages dynamic memory for the grades array.
*/

#include "BA.h"

// Default constructor
// Initializes a BA student with optional id, name, and number of courses.
// Allocates memory for grades if numberOfCourses > 0.
BA::BA(int id, string fn, string ln, int numCourses)
    : Student(id, fn, ln, numCourses)
{
    // Allocate memory for grades array if needed
    if (this->numberOfCourses > 0)
        this->grades = new int[this->numberOfCourses];
    else
        this->grades = nullptr;
}

// Copy constructor
// Creates a deep copy of another BA student, including grades array.
BA::BA(const BA& src)
    : Student(src)
{
    if (this->numberOfCourses > 0)
    {
        // Allocate memory for grades array
        this->grades = new int[this->numberOfCourses];
        // Copy over grades from source
        for (int i = 0; i < this->numberOfCourses; ++i)
            this->grades[i] = src.grades[i];
    }
    else
        this->grades = nullptr;
}

// Move constructor
// Transfers resources from another BA student, nullifying the source's grades pointer.
BA::BA(BA&& src) : Student(src), grades(src.grades)
{
    // Nullify the source's grades pointer to avoid double deletion
    src.grades = nullptr;
}

// Destructor
// Releases dynamic memory for grades.
BA::~BA()
{
    // Deallocate grades array memory if it exists
    if (this->grades)
        delete [] this->grades;
    this->grades = nullptr;
    this->numberOfCourses = 0;
}

// Copy assignment operator
// Assigns another BA student to this one (deep copy of grades).
BA& BA::operator=(const BA& src)
{
    // Handle self-assignment
    if (this == &src)
        return *this;
    
    // Copy base class members
    this->id = src.id;
    this->firstName = src.firstName;
    this->lastName = src.lastName;
    this->numberOfCourses = src.numberOfCourses;

    // Delete existing grades array if it exists
    if (this->grades)
        delete [] this->grades;
    // Allocate new grades array and copy values
    this->grades = new int[this->numberOfCourses];
    for (int i = 0; i < this->numberOfCourses; ++i)
        this->grades[i] = src.grades[i];
    
    return *this;
}

// Move assignment operator
// Moves another BA student's resources to this one, nullifying the source's grades pointer.
BA& BA::operator=(BA&& src)
{
    // Handle self-assignment
    if (this == &src)
        return *this;
    
    // Copy base class members
    this->id = src.id;
    this->firstName = src.firstName;
    this->lastName = src.lastName;
    this->numberOfCourses = src.numberOfCourses;

    // Delete existing grades array if it exists
    if (this->grades)
        delete [] this->grades;
    // Transfer grades pointer from source
    this->grades = src.grades;
    // Nullify source's grades pointer to avoid double deletion
    src.grades = nullptr;
    return *this;
}

// Determines if the student is eligible for a scholarship
// For BA: Signed up for at least 10 courses and has GPA over 95.
bool BA::milga() const
{
    // Must have at least 10 courses
    if (this->numberOfCourses < 10)
        return false;

    // Calculate sum of grades
    int gradeSum = 0;
    for (int i = 0; i < this->numberOfCourses; ++i)
        gradeSum += this->grades[i];

    // Calculate GPA and check eligibility
    return (gradeSum / this->numberOfCourses) >= 95;
}

// Prints student information and scholarship eligibility
void BA::print() const
{
    // First call parent method to print global student information
    this->Student::print();
    // Print BA-specific information: grades
    cout << "grades: ";
    for (int i = 0; i < this->numberOfCourses; ++i)
        cout << this->grades[i] << " ";
    cout << endl;
}

// Reads student information and grades from user input
void BA::input()
{
    // Delete existing grades array if it exists
    if (this->grades)
        delete [] this->grades;
    // Call parent method to get input for global fields
    this->Student::input();
    // Allocate new grades array based on updated numberOfCourses
    this->grades = new int[numberOfCourses];
    // Get BA-specific input: grades
    cout << "enter a list of student grades" << endl;
    for (int i = 0; i < this->numberOfCourses; ++i)
        cin >> this->grades[i];
}