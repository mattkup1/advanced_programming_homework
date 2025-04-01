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
    Polygon* polyArr[NUM_POLYGONS];  // Array of Polygon pointers

    for (int i = 0; i < NUM_POLYGONS; i++)
    {
        int userNumPoints;
        cout << "enter number of points:" << endl;
        cin >> userNumPoints;
    
        if (userNumPoints <= 0)
        {
            cout << "ERROR" << endl;
            continue;
        }

        polyArr[i] = new Polygon(userNumPoints); // Allocate on heap
        
        cout << "enter the point values:" << endl;

        char _;
        int x, y;

        for (int j = 0; j < userNumPoints; j++)
        { 
            cin >> _ >> x >> _ >> y >> _;
            polyArr[i]->setPoint(Point(x, y), j);
        }
    }

    // Polygon polCopy(*polyArr[1]);
    // delete polyArr[1];

    int perim1 = round(polyArr[0]->perimeter());
    int perim2 = round(polyArr[1]->perimeter());
    // int perim2 = round(polCopy.perimeter());

    if (polyArr[0]->isIdentical(*polyArr[1]))
    {
        cout << "equal" << endl <<
        "perimeter:" << perim1 << endl;
    }
    else 
    {
        cout << "not equal" << endl << 
        "perimeter:" << perim1 << endl << 
        "perimeter:" << perim2 << endl;
    }

    // Clean up memory
    // delete polyArr[0];

    for (int i = 0; i < NUM_POLYGONS; i++)
    {
        delete polyArr[i];
    }

    return 0;
}