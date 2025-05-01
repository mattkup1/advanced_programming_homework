/*
    Name: Matt Kuperwasser 322667270
    Course: Advanced Programming
    Homework 2, Question 1
    Description:
    This program reads two polygons from the user, stores them dynamically, compares
    them for geometric identity (regardless of point order), and prints their perimeters.
*/

#include <iostream>
#include <cmath>

#include "Point.h"
#include "Polygon.h"

using namespace std;

// Number of polygons in the array - per requirements
const int NUM_POLYGONS = 2;

int main()
{
    // Array of pointers to dynamically allocated Polygon objects
    // Only NUM_POLYGONS (2) polygons will be stored and compared
    Polygon* polyArr[NUM_POLYGONS];  // Array of Polygon pointers

    // Loop to input and construct each Polygon
    for (int i = 0; i < NUM_POLYGONS; i++)
    {
        int userNumPoints;
        cout << "enter number of points:" << endl;
        cin >> userNumPoints;

        // Input validation: number of points must be positive
        if (userNumPoints <= 0)
        {
            cout << "ERROR" << endl;
            continue;
        }

        // Dynamically allocate a Polygon object with the specified number of points
        polyArr[i] = new Polygon(userNumPoints); // Allocate on heap
        
        cout << "enter the point values:" << endl;

        char _;
        int x, y;

        // Input loop to read each point of the polygon from the user
        // Expected format: (x,y)
        for (int j = 0; j < userNumPoints; j++)
        { 
            cin >> _ >> x >> _ >> y >> _;
            polyArr[i]->setPoint(Point(x, y), j); // Store the user-entered point at index j
        }
    }

    // Calculate and round the perimeter of each polygon
    int perim1 = round(polyArr[0]->perimeter());
    int perim2 = round(polyArr[1]->perimeter());

    // Compare the two polygons for identity (same set of points, any order)
    if (polyArr[0]->isIdentical(*polyArr[1]))
    {
        // If polygons are identical, print a single perimeter value
        cout << "equal" << endl <<
        "perimeter:" << perim1 << endl;
    }
    else 
    {
        // If polygons differ, print both perimeter values
        cout << "not equal" << endl << 
        "perimeter:" << perim1 << endl << 
        "perimeter:" << perim2 << endl;
    }

    // Release memory allocated for each Polygon - Will invoke dtor
    for (int i = 0; i < NUM_POLYGONS; i++)
        delete polyArr[i];

    // Indicate successful program termination
    return 0;
}