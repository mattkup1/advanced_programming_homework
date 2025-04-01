#include "Point.h"

#include <iostream>

using namespace std;

// Constructors:
// Default Constructor (No parameters)
// Assignes 0 to X and Y as the default value
Point::Point() : x(0), y(0) 
{
    cout << "in point default constructor" << endl;
}

// Constructor (With parameters)
// Assigmes the argument values to X and Y
Point::Point(double x, double y) : x(x), y(y) 
{
    cout << "in point two parameter constructor" << endl;
}

// Copy Constructor
Point::Point(Point &p)
{
    this->x = p.x;
    this->y = p.y;

    cout << "in point copy constructor" << endl;
}


// Setters:
// X Setter
void Point::setX(double n)
{
    this->x = n;
}

// Y Setter
void Point::setY(double n)
{
    this->y = n;
}


// Getters:
// X Getter
const double& Point::getX() const
{
    return this->x;
}

// Y Getter
const double& Point::getY() const
{
    return this->y;
}

// 
double Point::distance(Point &p) const
{
    double dx = this->x - p.getX();
    double dy = this->y - p.getY();

    return sqrt((dx * dx) + (dy * dy));
}


bool Point::isEqual(Point &p) const
{
    return (this->x == p.getX() && this->y == p.getY());
}