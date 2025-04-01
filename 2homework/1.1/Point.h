#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    // X and Y coordinates
    double x;
    double y;

public:
    // Constructors:
    // Default Constructor
    // Assignes 0 to X and Y as the default value
    Point();

    // Constructor (With parameters)
    Point(double x, double y);

    // Copy Constructor
    Point(Point&);

    // Methods:
    // X and Y Setters
    void setX(double);
    void setY(double);

    // X and Y Getters
    const double& getX() const;
    const double& getY() const;

    // Returns the distance between the calling point
    // and the argument point
    double distance(Point&) const;

    // Returns the equality state between the calling point
    // and the argument point
    bool isEqual(Point &) const;
};