#pragma once

#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    int id;
    string firstName;
    string lastName;
    int numberOfCourses;

public:
    // Default ctor
    Student(int id = 0, string fn = "", string ln = "", int numCourses = 0);
    // Copy ctor
    Student(const Student&);
    // Virtual dtor
    virtual ~Student();

    // Abstract method to compute whether the student is eligible for scholarship
    virtual bool milga() const = 0;
    // Abstract method that returns the student type (BA / MA / PHD)
    virtual string studType() const = 0;
    // Method to print student information and scholarship elegibility
    virtual void print() const;
    // Method to get student information from the user
    virtual void input();
};