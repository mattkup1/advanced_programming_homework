/*
    MA.cpp:
    Implementation file for the MA (Master of Arts) class, derived from the BA class.
    This file defines the constructors, destructor, copy/move operations, and overrides for scholarship eligibility,
    student type identification, input, and output. The class adds a research flag to the BA student.
*/

#include "MA.h"

// Default constructor
// Initializes an MA student with optional id, name, and number of courses.
// Sets research flag to false by default.
MA::MA(int id, string fn, string ln, int numCourses)
    : BA(id, fn, ln, numCourses), research(false)
{}

// Copy constructor
// Creates a deep copy of another MA student, including the research flag.
MA::MA(const MA& src) : BA(src), research(src.research) {}

// Move constructor
// Transfers resources from another MA student, including the research flag.
MA::MA(MA&& src) : BA(std::move(src)), research(src.research) {}

// Destructor
// No dynamic memory in MA, but calls base class destructor.
MA::~MA()
{
    // No need to explicitly call base destructor; done automatically.
}

// Copy assignment operator
// Assigns another MA student to this one (deep copy of research flag and grades).
MA& MA::operator=(const MA& src)
{
    // Call base class assignment operator
    BA::operator=(src);
    // Copy research flag
    this->research = src.research;
    return *this;
}

// Move assignment operator
// Moves another MA student's resources to this one, including the research flag.
MA& MA::operator=(MA&& src)
{
    // Call base class move assignment operator
    BA::operator=(std::move(src));
    // Move research flag
    this->research = src.research;
    return *this;
}

// Determines if the student is eligible for a scholarship
// For MA: Must be signed up for at least 7 courses, engaged in research, and have GPA over 90.
bool MA::milga() const
{
    // Check minimum courses and research flag
    if (numberOfCourses < 7 || !research)
        return false;
    
    // Calculate sum of grades
    int gradeSum = 0;
    for (int i = 0; i < this->numberOfCourses; ++i)
        gradeSum += this->grades[i];
    
    // Calculate GPA and check eligibility
    return (gradeSum / this->numberOfCourses) >= 90;
}

// Prints student information and scholarship eligibility
void MA::print() const
{
    // Call parent method for global student information and grades
    this->BA::print();
    // Print MA-specific information: research flag
    cout << "research: " << (this->research ? "YES" : "NO") << endl;
}

// Reads student information and research flag from user input
void MA::input()
{
    // Call parent method to get input for global fields and grades
    this->BA::input();
    // Get MA-specific input: research flag
    char r;
    cout << "research? enter Y or N" << endl;
    cin >> r;
    cin.clear();
    // Set research flag based on user input (accepts only 'Y' as true)
    this->research = (r == 'Y');
}