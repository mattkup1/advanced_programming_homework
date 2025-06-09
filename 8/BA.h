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
    // dtor
    virtual ~BA() override;
    // Copy assignment
    BA& operator=(const BA&);
    // Move assignment
    BA& operator=(BA&&);

    // Grades getter
    virtual int* getGrades() const { return this->grades; }

    // Method to compute whether the student is eligible for scholarship
    bool milga() const override;
    // Method that returns the student type
    string studType() const override { return "BA student"; }
    // Method to print student information and scholarship elegibility
    virtual void print() const override;
    // Method to get student information from the user
    virtual void input() override;
};