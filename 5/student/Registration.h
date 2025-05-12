#pragma once

#include <fstream>
#include <string>
#include "Student.h"

class Registration
{
private:
    fstream* fileObj;

public:
    // ctor
    Registration(const string&);
    // dtor
    ~Registration();
    bool createFile(const string&);
    Student readStudent(const int&);
    void writeStudent(const Student&);
};