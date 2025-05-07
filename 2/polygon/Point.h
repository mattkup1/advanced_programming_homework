/*
    Name: Matt Kuperwasser 322667270
    Course: Advanced Programming
    Homework 2, Question 1
    Point class header file
    Definition of the Point class used to represent 2D points.
*/

#pragma once

#include <iostream>
#include <cmath>

using namespace std;

// The Point class encapsulates a 2D point with X and Y coordinates.
// Provides functionality for comparing points and calculating distance.
class Point
{
private:
    double x;  // X-coordinate of the point
    double y;  // Y-coordinate of the point

public:
    Point();                          // Default constructor: initializes point at origin (0,0)
    Point(double x, double y);         // Constructor: initializes point with specified X and Y coordinates
    Point(const Point& src);           // Copy constructor: creates a new Point as a copy of another

    void setX(double);                 // Sets the X-coordinate value (requires cast due to const member)
    void setY(double);                 // Sets the Y-coordinate value (requires cast due to const member)
    const double& getX() const;        // Returns a constant reference to the X-coordinate
    const double& getY() const;        // Returns a constant reference to the Y-coordinate
    double distance(Point&) const;     // Calculates and returns the Euclidean distance between this point and another
    bool isEqual(Point&) const;        // Compares this point with another and returns true if they have the same coordinates
};