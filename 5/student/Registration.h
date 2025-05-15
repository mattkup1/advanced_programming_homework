#pragma once

#include <fstream>
#include <string>
#include "Student.h"

class Registration
{
private:
    fstream fileObj;
    // Function to create a binary file and signal success on open
    bool createFile(const string&);
    // Funciton that reads and returns a student from the file with the given id argument
    Student readStudent(const int&);
    // Function to write the argumented student to the file
    void writeStudent(const Student&);

public:
    // ctor
    Registration(const string&);
    // dtor
    ~Registration();

    void addStudent();
    void deleteStudent();
    void update();
    bool checkRegistered();
    void printStudent();
    void printAll();
};