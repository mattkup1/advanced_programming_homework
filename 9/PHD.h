/*
    PHD.h:
    Declaration of the PHD (Doctor of Philosophy) class, derived from the abstract Student class.
    This class represents a PHD student in the university system, adding management of weekly research hours.
    It provides constructors, destructor, copy/move operations, and overrides for scholarship eligibility,
    student type identification, input, and output.
*/

#pragma once

#include "Student.h"

// PHD Class: Represents a PHD student with weekly research hours
class PHD : public Student
{
private:
    int weeklyResearchHrs; // Number of weekly research hours

public:
    // Default constructor
    // Initializes a PHD student with optional id, name, number of courses, and research hours
    PHD(int id = 0, string fn = "", string ln = "", int numCourses = 0, int hrs = 0);

    // Copy constructor
    // Creates a deep copy of another PHD student
    PHD(const PHD&);

    // Move constructor
    // Transfers resources from another PHD student
    PHD(PHD&&);

    // Copy assignment operator
    // Assigns another PHD student to this one (deep copy)
    PHD& operator=(const PHD&);

    // Move assignment operator
    // Moves another PHD student's resources to this one
    PHD& operator=(PHD&&);

    // Weekly Research Hours Getter
    // Returns the number of weekly research hours
    int getWeeklyResearchHrs() const { return this->weeklyResearchHrs; }

    // Weekly Research Hours Setter
    // Sets the number of weekly research hours
    void setWeeklyResearchHrs(int h) { this->weeklyResearchHrs = h; }

    // Determines if the student is eligible for a scholarship
    bool milga() const override final;

    // Returns the student type as a string
    string studType() const override final { return "PHD"; }

    // Prints student information and scholarship eligibility
    void print() const override final;

    // Reads student information and research hours from user input
    void input() override final;
};