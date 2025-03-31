#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    // Default Constructor
    Point();
    // Constructor (With parameters)
    Point(float x, float y);
    // Copy Constructor
    Point(Point&);

    // Setters
    void setX(float);
    void setY(float);

    // Getters
    const float& getX() const;
    const float& getY() const;

    // Get distance between a point and the argument point
    float distance(Point&) const;

    bool isEqual(Point &) const;
};