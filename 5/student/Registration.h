#pragma once

#include <fstream>
#include <string>
#include "Student.h"

const int NUM_STUDENTS = 100;

class Registration
{
public:
    // ctor
    Registration(const string&);
    // dtor
    ~Registration();

    // Function to add a student to the file
    void addStudent();
    // Function to delete a student from the file (Set to empty Student obj)
    void deleteStudent();
    // Function to update registered courses for a student in the file
    void update();
    // Function to check course registration state for a student in the file 
    void checkRegistered();
    // Function to print info of a single student to terminal
    void printStudent();
    // Function to print all student's info to terminal
    void printAll();

    // Helper function
    bool findStudent(const int& id);

private:
    fstream fileObj;
    // Function to create a binary file and signal success on open
    bool createFile(const string&);
    // Funciton that reads and returns a student from the file with the given id argument
    Student readStudent(const int&);
    // Function to write the argumented student to the file
    void writeStudent(const Student&);
};