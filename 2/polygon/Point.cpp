#include "Point.h"

// point.cpp
// Implementation of the Point class, including constructors, setters, getters, distance calculation,
// and comparison functionality.

// Default constructor: Initializes point to the origin (0, 0)
// Outputs message to indicate that the default constructor is called
Point::Point() : x(0), y(0) 
{
    cout << "in point default constructor" << endl;
}

// Parameterized constructor: Initializes point with specified x and y values
// Outputs message to indicate that the parameterized constructor is called
Point::Point(double x, double y) : x(x), y(y) 
{
    cout << "in point two parameter constructor" << endl;
}

// Copy constructor: Initializes point by copying the coordinates from another Point object
// Outputs message to indicate that the copy constructor is called
Point::Point(const Point& src) : x(src.getX()), y(src.getY())
{
    cout << "in point copy constructor" << endl;
}

// Setters:
// Sets the X-coordinate value of the point
void Point::setX(double n)
{
    this->x = n;
}

// Sets the Y-coordinate value of the point
void Point::setY(double n)
{
    this->y = n;
}

// Getters:
// Getter for the X-coordinate value
// Returns a constant reference to the X-coordinate for access
const double& Point::getX() const
{
    return this->x;
}

// Getter for the Y-coordinate value
// Returns a constant reference to the Y-coordinate for access
const double& Point::getY() const
{
    return this->y;
}

// Calculates the Euclidean distance between this point and another point 'p'
// Uses the Pythagorean theorem to calculate distance: sqrt(dx^2 + dy^2)
double Point::distance(Point &src) const
{
    double dx = this->x - src.getX();
    double dy = this->y - src.getY();

    return sqrt((dx * dx) + (dy * dy));
}

// Compares this point to another point 'src'
// Returns true if both x and y coordinates are the same
bool Point::isEqual(Point &src) const
{
    return (this->x == src.getX() && this->y == src.getY());
}