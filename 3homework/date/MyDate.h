#pragma once

#include <iostream>

using namespace std;


const int DAYS_IN[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;

bool checkDate(const int& d, const int& m, const int& y);
bool leapYear(const int& y);
int daysInMonth(const int& m, const int& y);

class MyDate
{
private:
    int day;
    int month;
    int year;

public:
    // Ctors
    // Default Constructor
    MyDate(const int day = 1, const int month = 1, const int year = 1899);
    // Copy Constructor
    MyDate(const MyDate&);
    // Move Constructor
    MyDate(MyDate&&);

    // Methods
    // Getters
    int getDay() const { return this-> day; }
    int getMonth() const { return this-> month; }
    int getYear() const { return this->year; }

    // Setter
    void setDate(const int d, const int m, const int y);

    void print() const;

    // Operators
    // Move assignment '='
    MyDate& operator=(const MyDate&);
    MyDate& operator++();
    MyDate operator++(int);

    // Comparison
    bool operator==(const MyDate&) const;
    bool operator<(const MyDate&) const;
    bool operator>(const MyDate&) const;
};