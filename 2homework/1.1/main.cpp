/*
    Name: Matt Kuperwasser 322667270
    Course: Advanced Programming
    Homework 2, Question 1
    Description:
*/

#include <iostream>
#include <cmath>

#include "Point.h"
#include "Polygon.h"

const int NUM_POLYGONS = 2;

using namespace std;

int main()
{
    Polygon polyArr[NUM_POLYGONS];
    int userNumPoints;

    for (int i = 0; i < NUM_POLYGONS; i++)
    {
        cout << "enter number of points:" << endl;
        cin >> userNumPoints;
    
        if (userNumPoints <= 0)
            cout << "ERROR" << endl;
    
        Polygon p(userNumPoints);
        
        cout << "enter the point values:" << endl;
    
        char _;
        int x, y;
    
        for (int i = 0; i < userNumPoints; i ++)
        { 
            // Take input in the form "(x,y)"
            cin >> _ >> x >> _ >> y >> _;
            // Point pnt(x, y);
            p.setPoint(Point(x, y), i);
        }

        polyArr[i] = p;
    }


    int prim1 = round(polyArr[0].primeter());
    int prim2 = round(polyArr[1].primeter());

    if (prim1 == prim2)
    {
        cout << "equal" << endl <<
        "primeter: " << prim1 << endl;
    }
    else 
    {
        cout << "not equal" << endl << 
        "primeter: " << prim1 << endl << 
        "primeter: " << prim2 << endl;
    }

    for (int i = 0; i < NUM_POLYGONS; i++)
        polyArr[i].~Polygon();

    return 0;
}