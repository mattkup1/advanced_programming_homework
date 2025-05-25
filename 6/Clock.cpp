#include "Clock.h"


Clock::Clock(int h, int m, int s)
{
    if (s < 0 || s > MAX_SECOND)
        throw SECOND_ERROR;
    if (m < 0 || m > MAX_MINUTE)
        throw MINUTE_ERROR;
    if (h < 0 || h > MAX_HOUR)
        throw HOUR_ERROR;

    this->hour = h;
    this->minute = m;
    this->second = s;
}


// Methods
// Setters
void Clock::setHour(int h)
{
    if (h < 0 || h > MAX_HOUR)
        throw HOUR_ERROR;
    this->hour = h;
}


void Clock::setMinute(int m)
{
    if (m < 0 || m > MAX_MINUTE)
        throw MINUTE_ERROR;
    this->minute = m;
}


void Clock::setSecond(int s)
{
    if (s < 0 || s > MAX_SECOND)
        throw SECOND_ERROR;
    this->second = s;
}


// Operators
// += operator to add argumented seconds
Clock& Clock::operator+=(int s)
{
    if (s < 0)
        throw SECOND_ERROR;
    
    // Increment and format second
    this->second = s % (MAX_SECOND + 1);
    // Increment minute without formatting
    this->minute += s / (MAX_SECOND + 1);
    // Increment hour
    this->hour += (this->minute / (MAX_MINUTE + 1)) % (MAX_HOUR + 1);
    // Format minute
    this->minute %= (MAX_MINUTE + 1);

    return *this;
}   


// Output << operator
ostream& operator<<(ostream& os, const Clock& c)
{
    int h = c.getHour(), m = c.getMinute(), s = c.getHour();
    return os << (h < 10 ? "0" : "") << h 
              << (m < 10 ? "0" : "") << m
              << (s < 10 ? "0" : "") << s;
}


istream& operator>>(istream& is, Clock& c)
{
    is >> c.hour >> c.minute >> c.second;

    if (c.second < 0 || c.second > MAX_SECOND)
    {
        c.second = c.hour = c.minute = 0;
        throw SECOND_ERROR;
    }
    if (c.minute < 0 || c.minute > MAX_MINUTE)
    {
        c.second = c.hour = c.minute = 0;
        throw MINUTE_ERROR;
    }
    if (c.hour < 0 || c.hour > MAX_HOUR)
    {
        c.second = c.hour = c.minute = 0;
        throw HOUR_ERROR;
    }
    return is;
}