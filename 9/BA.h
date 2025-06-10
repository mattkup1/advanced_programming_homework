/*
    BA.h:
    Declaration of the BA (Bachelor of Arts) class, derived from the abstract Student class.
    This class represents a BA student in the university system, adding management of student grades.
    It provides constructors, destructor, copy/move operations, and overrides for scholarship eligibility,
    student type identification, input, and output. The class manages dynamic memory for the grades array.
*/

#pragma once

#include "Student.h"

// BA Class: Represents a BA student with grades
class BA : public Student
{
protected:
    int* grades; // Dynamic array of student grades

public:
    // Default constructor
    // Initializes a BA student with optional id, name, and number of courses
    BA(int id = 0, string fn = "", string ln = "", int numCourses = 0);

    // Copy constructor
    // Creates a deep copy of another BA student
    BA(const BA&);

    // Move constructor
    // Transfers resources from another BA student
    BA(BA&&);

    // Destructor
    // Releases dynamic memory for grades
    virtual ~BA() override;

    // Copy assignment operator
    // Assigns another BA student to this one (deep copy)
    BA& operator=(const BA&);

    // Move assignment operator
    // Moves another BA student's resources to this one
    BA& operator=(BA&&);

    // Grades getter
    // Returns a pointer to the grades array
    virtual int* getGrades() const { return this->grades; }

    // Determines if the student is eligible for a scholarship
    bool milga() const override;

    // Returns the student type as a string
    string studType() const override { return "BA student"; }

    // Prints student information and scholarship eligibility
    virtual void print() const override;

    // Reads student information and grades from user input
    virtual void input() override;
};