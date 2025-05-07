#include "Worker.h"


// Operators
// Adds argument to monthly salary
Worker& Worker::operator+=(const float raise)
{
    // Increase salary by given raise
    this->salary += raise;
    // Return reference to updated worker
    return *this;
}

// Friend functions
// Compare id (Worker == int)
bool operator==(const Worker& w, const int id)
{
    return (w.id == id);
}

// Compare id (int == Worker)
bool operator==(const int id, const Worker& w)
{
    return (w.id == id);
}


// Compare name (Worker == string)
bool operator==(const Worker& w, const string& s)
{
    string tmp = w.name;
    return (tmp == s);
}


// Compare name (string == Worker)
bool operator==(const string& s, const Worker& w)
{
    return (w == s);
}


// Input
istream& operator>>(istream& is, Worker& w)
{
    // Create a temp string for the name
    string tmp;
    // Stream the input
    is >> w.id >> tmp >> w.salary;

    // Free previous name
    delete [] w.name;
    // Allocate memory for input name
    w.name = new char[tmp.length() + 1];
    // Copy temp name to object name field
    strcpy(w.name, tmp.c_str());
    // Return the input stream
    return is;
}


// Output
ostream& operator<<(ostream& os, const Worker& w)
{
    os << w.id << " " << w.name << " " << w.salary << endl;
    return os;
}

