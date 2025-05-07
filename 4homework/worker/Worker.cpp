#include "Worker.h"


    // Operators
    // Adds argument to monthly salary
    Worker& Worker::operator+=(const float raise)
    {
        this->salary += raise;
        return *this;
    }

    // Friend functions
    // Compare id
    bool operator==(const Worker& w, const int id)
    {
        return (w.id == id);
    }

    bool operator==(const int id, const Worker& w)
    {
        return (w.id == id);
    }


    // Compare name
    bool operator==(const Worker& w, const string& s)
    {
        string tmp = w.name;
        return (tmp == s);
    }


    bool operator==(const string& s, const Worker& w)
    {
        return (w == s);
    }


    // Input
    istream& operator>>(istream& is, Worker& w)
    {
        string tmp;
        is >> w.id >> tmp >> w.salary;

        delete [] w.name;
        w.name = new char[tmp.length() + 1];
        strcpy(w.name, tmp.c_str());
        return is;
    }


    // Output
    ostream& operator<<(ostream& os, const Worker& w)
    {
        os << w.id << " " << w.name << " " << w.salary << endl;
        return os;
    }

