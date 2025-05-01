#include "MyDate.h"


// Default ctor
MyDate::MyDate(const int d, const int m, const int y)
    : day(d), month(m), year(y)
{
    if (!checkDate(d, m, y))
    {
        this->day = this->month = 1;
        this->year = 1899;
    }
}


// Copy ctor
MyDate::MyDate(const MyDate& src)
    : year(src.getYear()), month(src.getMonth()), day(src.getDay())
{}


// Move ctor
MyDate::MyDate(MyDate&& src)
    : year(src.getYear()), month(src.getMonth()), day(src.getDay())
{}


bool leapYear(const int& y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}


int daysInMonth(const int& m, const int& y)
{
    // Special case for February
    if (m == 2)
        return (leapYear(y) ? 29 : 28);
    else
        return DAYS_IN[m];
}


// Helper function to validate a given date
bool checkDate(const int& d, const int& m, const int& y) 
{
    // Validate year
    if (y < 1899 || y > 9999)
        return false;
    // Validate month
    if (m < 1 || m > 12)
        return false;
    // Validate day
    if (d <= 0 || d > daysInMonth(m))
        return false;

    return true;
}


// Setter
void MyDate::setDate(const int d, const int m, const int y)
{
    if (!checkDate(d, m, y))
        return;
    
    this->day = d, this->month = m, this->year = y;
}


void MyDate::print() const
{
    cout << this->day << "/" << this->month << "/" << this->year;
}


                    /////////////////////// Operators ///////////////////////////
// Assignment '='
MyDate& MyDate::operator=(const MyDate& src)
{
    this->day = src.getDay();
    this->month = src.getMonth();
    this->year = src.getYear();

    return *this;
}


// Left side '++' operator
MyDate& MyDate::operator++()
{
    // Increase day, Wrap if last day of month
    this->day = this->day % daysInMonth(this->month, this->year) + 1;

    // Case last day of month
    if (this->day == 1)
    {
        // Increase month, Wrap if December
        this->month = (this->month % 12) + 1;
        // Case last day of year
        if (month == 1)
            ++this->year;
    }
    return *this;
}


// Right side '++' operator
MyDate MyDate::operator++(int)
{
    MyDate tmp(*this);
    // Use the already implemented left side '++' operator
    ++*this;
    return tmp;
}


                    ///////////////////////// Comparison /////////////////////////
// 
bool MyDate::operator==(const MyDate& d) const
{
    return (this->day == d.getDay() &&
            this->month == d.getMonth() &&
            this-> year == d.getYear());
}


bool MyDate::operator<(const MyDate& d) const
{
    if (this->year < d.getYear())
        return true;
    else if (this->year > d.getYear())
        return false;
    
    // Case same year
    if (this->month < d.getMonth())
        return true;
    else if (this->month > d.getMonth())
        return false;

    // Case same year and month
    if(this->day < d.getDay())
        return true;
    
    return false;
}


bool MyDate::operator>(const MyDate& d) const
{
    return !(*this < d || *this == d);
}