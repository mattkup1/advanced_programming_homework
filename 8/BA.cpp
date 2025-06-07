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
    BA tmp(src);
}


// Move assignment
BA& BA::operator=(BA&&)
{

}


// Abstract method to compute whether the student is eligible for scholarship
bool BA::milga() const
{

}


// Abstract method that returns the student type (BA / MA / PHD)
string BA::studType() const
{
    
}