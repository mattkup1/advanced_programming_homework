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
    virtual ~Student() {}

    // ID Getter
    virtual int getId() const { return this->id; };
    // First Name Getter
    virtual const string& getFn() const { return this->firstName; }
    // Last Name Getter
    virtual const string& getLn() const { return this->lastName; }
    // Number of courses Getter
    virtual int getNumCourses() const { return this->numberOfCourses; }

    // ID Setter
    virtual void setId(const int& id_) { this->id = id_; }
    // First Name Setter
    virtual void setFn(const string& fn) { this->firstName = fn; }
    // Last Name Setter
    virtual void setLn(const string& ln) { this->lastName = ln; }

    // Abstract method to compute whether the student is eligible for scholarship
    virtual bool milga() const = 0;
    // Abstract method that returns the student type (BA / MA / PHD)
    virtual std::string studType() const = 0;
    // Method to print student information and scholarship elegibility
    virtual void print() const;
    // Method to get student information from the user
    virtual void input();
};