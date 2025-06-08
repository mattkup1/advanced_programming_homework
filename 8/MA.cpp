#include "MA.h"

// Default ctor
MA::MA(int id, string fn, string ln, int numCourses)
    : BA(id, fn, ln, numCourses), research(false)
{}


// Copy ctor
MA::MA(const MA& src) : BA(src), research(src.research) {}


// Move ctor
MA::MA(MA&& src) : BA(src), research(src.research) {}


// Copy assignment
MA& MA::operator=(const MA& src)
{
    BA::operator=(src);
    this->research = src.research;
    return *this;
}


// Move assignment
MA& MA::operator=(MA&& src)
{
    BA::operator=(src);
    this->research = src.research;
    return *this;
}


// Method to compute whether the student is eligible for scholarship
// For MA: Signed up for at least 7 courses, Engages in research and has GPA over 90
bool MA::milga() const
{
    if (numberOfCourses < 7 || !research)
        return false;
    
    int gradeSum = 0;
    for (int i = 0; i < this->numberOfCourses; ++i)
        gradeSum += this->grades[i];
    
    return (gradeSum / this->numberOfCourses) > 90;
}


// Method to print student information and scholarship elegibility
void MA::print() const
{
    // First call parent method
    this->BA::print();
    // Print MA specifics
    cout << "research: " << (this->research ? "YES" : "NO") << endl;
}


// Method to get student information from the user
void MA::input()
{
    // Call parent method to get input to global fields
    this->BA::input();
    // Get specific MA input
    char r;
    cout << "research? enter Y or N" << endl;
    cin >> r;
    this->research = (r == 'Y');
}