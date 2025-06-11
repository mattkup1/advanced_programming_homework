/*
    MA.h:
    Declaration of the MA (Master of Arts) class, derived from the BA class.
    This class represents an MA student in the university system, adding a research flag to the BA student.
    It provides constructors, destructor, copy/move operations, and overrides for scholarship eligibility,
    student type identification, input, and output.
*/

#pragma once

#include "BA.h"

// MA Class: Represents an MA student with a research flag
class MA : public BA
{
private: 
    bool research; // Indicates if the student is involved in research

public:
    // Default constructor
    // Initializes an MA student with optional id, name, and number of courses
    MA(int id = 0, string fn = "", string ln = "", int numCourses = 0);
    // Copy constructor
    // Creates a deep copy of another MA student
    MA(const MA&);
    // Move constructor
    // Transfers resources from another MA student
    MA(MA&&);
    // Destructor
    // Releases any resources (calls base destructor)
    ~MA() override;
    // Copy assignment operator
    // Assigns another MA student to this one (deep copy)
    MA& operator=(const MA&);
    // Move assignment operator
    // Moves another MA student's resources to this one
    MA& operator=(MA&&);

    // Research getter
    // Returns true if the student is involved in research
    bool getResearch() const { return this->research; }
    // Research setter
    // Sets the research flag
    void setResearch(bool r) { this->research = r; }

    // Determines if the student is eligible for a scholarship
    bool milga() const override final;
    // Returns the student type as a string
    string studType() const override final { return "MA"; }
    // Prints student information and scholarship eligibility
    void print() const override final;
    // Reads student information and research flag from user input
    void input() override final;
};