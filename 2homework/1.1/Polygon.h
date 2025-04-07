#pragma once

#include "Point.h" // includes iosttream and namespace

class Polygon
{
private:
    Point *points;          // Dynamically allocated array for the Polygon Points 
    const int numPoints;    // Number of points in the Polygon (const after initialization)

public:
    Polygon();                  // Default ctor, Creates an empty Polygon
    Polygon(int numPoints);     // Parameterized ctor, Allocates memory for 'numPoints'
    Polygon(Polygon&);          // Copy ctor, Creates a deep copy of another Polygon
    ~Polygon();                 // Destructor, Deallocates the points array


    // Getters:
    const int& getNumPoints() const;            // Returns the number of points in the Polygon 
    Point* getPoints() const;                   // Returns a deep copy of the polygon's points array
    void setPoint(const Point, int index);      // Sets a Point at the given index in the polygon's points array
    double perimeter() const;                   // Computes and returns the perimeter for the Polygon
    bool isIdentical(const Polygon) const;      // Checks if caller and callee have the same points regardless to order of Points
};