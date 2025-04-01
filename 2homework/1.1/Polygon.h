#pragma once

#include <iostream>

#include "Point.h"

using namespace std;


class Polygon
{
private:
    Point *points;
    int numPoints;

public:
    // Default constructor
    Polygon();
    // Constructor (with parameters)
    Polygon(int numPoints);
    // Copy Constructor
    Polygon(Polygon&);

    // Destructor
    ~Polygon();


    // Getter
    const int& getNumPoints() const;

    Point* getPoints() const;

    void setPoint(const Point, int index);

    double perimeter() const;

    bool isIdentical(const Polygon) const;
};