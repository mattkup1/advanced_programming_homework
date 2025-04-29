#pragma once

enum MONTHS { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
const int DAYS_IN[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;

class MyDate
{
private:
    int day;
    int month;
    int year;

public:
    // Default Constructor
    MyDate(int day = 1, int month = 1, int year = 1899);
    // Copy Constructor
    MyDate(const MyDate&);
    // Move Constructor
    MyDate(MyDate&&);
};