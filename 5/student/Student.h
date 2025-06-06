#pragma once

#include <cstring>
#include <iostream>
using namespace std;

#define NUM_COURSES 5
#define MAX_NAME_LEN 20

class Student
{
public:
    // Default ctor
    Student();
    // Assignment ctor
    Student(const int& id, const char* fn, const char* ln);

    // Methods
    int getId() const { return this->id; }

    // Operators
    bool operator[](const int& courseId) const;
    // Output operator <<
    friend ostream& operator<<(ostream&, const Student&);
    // Input operator >>
    friend istream& operator>>(istream&, Student&);

    // Helper functions
    int findStudent(const int& id);

private:
    int id;
    char firstName[MAX_NAME_LEN + 1];
    char lastName[MAX_NAME_LEN + 1];
    bool courses[NUM_COURSES] = {};
};