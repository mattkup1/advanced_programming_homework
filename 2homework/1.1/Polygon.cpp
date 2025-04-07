#include "Polygon.h"

#include <iostream>

using namespace std;

// Default constructor: initializes an empty polygon with zero points
Polygon::Polygon() : points(nullptr), numPoints(0) {}

// Parameterized constructor: initializes polygon with 'n' points
// Dynamically allocates array for 'n' Point objects
Polygon::Polygon(int n) : numPoints(n), points(new Point[n])
{
    cout << "in poly one parameter constructor" << endl;
}

// Copy constructor: creates a deep copy of another Polygon object
// Copies the number of points and uses getPoints() to deep copy the array
Polygon::Polygon(Polygon &src) :
    numPoints(src.getNumPoints()), points(src.getPoints())
{
    cout << "in poly copy constructor" << endl;
}

// Destructor: deallocates the dynamically allocated array of points
Polygon::~Polygon()
{   
    delete [] this->points;
    cout << "in destructor" << endl;
}

// Getter: returns reference to the number of points in the polygon
const int& Polygon::getNumPoints() const
{
    return this->numPoints;
}

// Getter: returns a deep copy of the points array
// Helper function for copy ctor
// Memory is eventually deleted via destructor
Point* Polygon::getPoints() const
{
    int n = this->getNumPoints();
    Point* newArr = new Point[n];
    // Copy each point individually into new array
    for (int i = 0; i < n; i++)
        newArr[i] = this->points[i];
    
    return newArr;
}

// Sets the coordinates of a point at the given index in the polygon
// Performs bounds check to ensure valid index
void Polygon::setPoint(const Point p, int index)
{
    if (index >= 0 && index < this->numPoints)
    {
        this->points[index].setX(p.getX());
        this->points[index].setY(p.getY());
    }
}

// Computes the perimeter by summing distances between consecutive points
// Also adds distance between last and first point to close the polygon
double Polygon::perimeter() const
{
    double prim = 0;
    // Sum distances between each consecutive pair of points
    for (int i = 0; i < this->numPoints - 1; i++)
    {
        prim += this->points[i].distance(this->points[i + 1]);
    }
    // Add the distance from last to first Point to complete the loop
    prim += this->points[this->numPoints - 1].distance(this->points[0]);

    return prim;
}

// Checks whether caller polygon and callee contain the same set of points
// Regardless to order
bool Polygon::isIdentical(const Polygon src) const
{
    int srcNumPoints = src.getNumPoints();

    if (this->numPoints != srcNumPoints)
        return false;
    
    bool found = false;
    // Check each point in this polygon
    for (int i = 0; i < this->numPoints; i ++)
    {
        found = false;
        // Compare against all points in source polygon
        for (int j = 0; j < srcNumPoints; j ++)
        {
            // If a match is found, mark it as found
            if (this->points[i].isEqual(src.points[j]))
                found = true;
        }
        // If no match was found, polygons are not identical
        if (!found) return false;
    }
    return true;
}
