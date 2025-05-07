#pragma once

#include "Worker.h"

#include <fstream>

class WorkersFile
{
private:
    string fileName;
    fstream iofile;

    bool openFileForWriting();
    bool openFileForReading();
    void closeFile();

public:
    // ctor
    WorkersFile(const string&);

    // Operators
    // Get Worker by id
    Worker operator[](const int&);
    // Get worker by name
    Worker operator[](const string&);
    // Increase all workers salaries
    WorkersFile& operator+=(const float&);

    // Friend functions
    // Input workers information to file
    friend istream& operator>>(istream&, WorkersFile&);
    // Print file to terminal
    friend ostream& operator<<(ostream&, WorkersFile&);
};