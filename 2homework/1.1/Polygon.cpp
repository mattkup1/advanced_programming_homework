#include "Polygon.h"

#include <iostream>

using namespace std;


// Default Constructor
Polygon::Polygon() : points(nullptr), numPoints(0) {}

// Constructor (with parameters)
Polygon::Polygon(int n)
{
    if (n > 0)
    {
        this->numPoints = n;
        this->points = new Point[n];

        cout << "in poly one parameter constructor" << endl;
    }
}

// Copy Constructor
Polygon::Polygon(Polygon &p)
{
    this->numPoints = p.getNumPoints();

    this->points = p.getPoints();

    cout << "in poly copy constructor" << endl;
}


// Destructor
Polygon::~Polygon()
{
    delete [] this->points;
    cout << "in destructor" << endl;
}


// Getter
const int& Polygon::getNumPoints() const
{
    return this->numPoints;
}


// Points Getter
Point* Polygon::getPoints() const
{
    int n = this->getNumPoints();
    Point* newArr = new Point[n];
    for (int i = 0; i < n; i++)
        newArr[i] = this->points[i];
    
    return newArr;
}


void Polygon::setPoint(const Point p, int index)
{
    if (index >= 0 && index < this->numPoints)
    {
        this->points[index].setX(p.getX());
        this->points[index].setY(p.getY());
    }
}


// Calculate the primeter
// The distance between each 2 points in the Polygon
float Polygon::perimeter() const
{
    float prim = 0;
    for (int i = 0; i < this->numPoints - 1; i++)
    {
        prim += this->points[i].distance(this->points[i + 1]);
    }
    // Add the distance between the last and first point
    prim += this->points[this->numPoints - 1].distance(this->points[0]);

    return prim;
}


// Check if the calling polygon is identical to the argument polygon
bool Polygon::isIdentical(const Polygon p) const
{
    int pNumPoints = p.getNumPoints();

    if (this->numPoints != pNumPoints)
        return false;
    
    bool found = false;
    for (int i = 0; i < this->numPoints; i ++)
    {
        found = false;
        for (int j = 0; j < pNumPoints; j ++)
        {
            if (this->points[i].isEqual(p.points[j]))
                found = true;
        }
        if (!found) return false;
    }
    return true;
}
