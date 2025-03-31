#include "Point.h"

#include <iostream>

using namespace std;


// Default Constructor (No parameters)
Point::Point() : x(0), y(0) 
{
    cout << "in point default constructor" << endl;
}

// Constructor (With parameters)
Point::Point(float x, float y) : x(x), y(y) 
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


// Setters
void Point::setX(float n)
{
    this->x = n;
}


void Point::setY(float n)
{
    this->y = n;
}


// Getters
const float& Point::getX() const
{
    return this->x;
}

const float& Point::getY() const
{
    return this->y;
}


float Point::distance(Point &p) const
{
    float dx = this->x - p.getX();
    float dy = this->y - p.getY();

    return sqrt((dx * dx) + (dy * dy));
}


bool Point::isEqual(Point &p) const
{
    return (this->x == p.getX() && this->y == p.getY());
}