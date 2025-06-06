#pragma once

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Worker
{
private:
    int id = 0;
    char* name = new char[1] {'\0'};
    double salary = 0.0;

public:
    // Operators
    // Adds argument to monthly salary
    Worker& operator+=(const float raise);

    // Friend functions
    // Comparison
    // Compare id
    friend bool operator==(const Worker&, const int id);
    friend bool operator==(const int id, const Worker&);
    // Compare name
    friend bool operator==(const Worker& w, const string&);
    friend bool operator==(const string&, const Worker&);

    // Input
    friend istream& operator>>(istream&, Worker&);
    // Output
    friend ostream& operator<<(ostream&, const Worker&);

};