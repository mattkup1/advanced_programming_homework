#pragma once

#include "Student.h"


class BA : public Student
{
protected:
    int* grades;

public:
    // Default ctor
    BA(int id = 0, string fn = "", string ln = "", int numCourses = 0);
    // Copy ctor
    BA(const BA&);
    // Move ctor
    BA(BA&&);
    // Assignment operator
    BA& operator=(const BA&);
    // Move assignment
    BA& operator=(BA&&);
    // Grades getter
    virtual int* getGrades() const;

    // Abstract method to compute whether the student is eligible for scholarship
    bool milga() const override;
    // Abstract method that returns the student type (BA / MA / PHD)
    string studType() const override;

};