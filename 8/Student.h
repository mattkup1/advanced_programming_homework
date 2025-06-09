#pragma once

/*
    Student.h

    Abstract base class for representing a student in the university system.
    This class defines the common interface and data members for all student types (BA, MA, PHD).
    It provides basic information such as ID, first name, last name, and number of courses.
    The class enforces implementation of scholarship eligibility and student type identification
    in derived classes via pure virtual methods. It also provides virtual methods for input and output.
*/

#include <iostream>
#include <string>
using namespace std;

// Abstract Class: Student
class Student
{
protected:
    int id;                 // Student's unique identifier
    string firstName;       // Student's first name
    string lastName;        // Student's last name
    int numberOfCourses;    // Number of courses the student is enrolled in

public:
    // Default constructor with optional parameters
    Student(int id = 0, string fn = "", string ln = "", int numCourses = 0);

    // Copy constructor
    Student(const Student&);

    // Virtual destructor for safe polymorphic deletion
    virtual ~Student() {}

    // Getters
    virtual int getId() const { return this->id; }                        // Get student ID
    virtual const string& getFn() const { return this->firstName; }       // Get first name
    virtual const string& getLn() const { return this->lastName; }        // Get last name
    virtual int getNumCourses() const { return this->numberOfCourses; }   // Get number of courses

    // Setters
    virtual void setId(const int& id_) { this->id = id_; }                // Set student ID
    virtual void setFn(const string& fn) { this->firstName = fn; }        // Set first name
    virtual void setLn(const string& ln) { this->lastName = ln; }         // Set last name

    // Pure virtual method: must be implemented by derived classes
    // Returns true if the student is eligible for a scholarship
    virtual bool milga() const = 0;

    // Pure virtual method: must be implemented by derived classes
    // Returns a string representing the student type (e.g., "BA", "MA", "PHD")
    virtual std::string studType() const = 0;

    // Virtual method to print student information and scholarship eligibility
    virtual void print() const;

    // Virtual method to get student information from the user
    virtual void input();
};