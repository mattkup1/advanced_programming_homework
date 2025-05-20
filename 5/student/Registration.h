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

    void addStudent();
    void deleteStudent();
    void update();
    void checkRegistered();
    void printStudent();
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