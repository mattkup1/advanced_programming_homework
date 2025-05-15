#pragma once

#include <fstream>
#include <string>
#include "Student.h"

class Registration
{
private:
    fstream fileObj;
    Student readStudent(const int&);
    void writeStudent(const Student&);

public:
    // ctor
    Registration(const string&);
    // dtor
    ~Registration();
    bool createFile(const string&);

    void addStudent();
    void deleteStudent();
    void update();
    bool checkRegistered();
    void printStudent();
    void printAll();
};