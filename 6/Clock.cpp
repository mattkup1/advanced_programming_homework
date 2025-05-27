#include "Clock.h"


Clock::Clock(int h, int m, int s)
{
    try
    {
        if (s < 0 || s > MAX_SECOND)
            throw SECOND_ERROR;
        if (m < 0 || m > MAX_MINUTE)
            throw MINUTE_ERROR;
        if (h < 0 || h > MAX_HOUR)
            throw HOUR_ERROR;
    }
    // Case invalid input
    catch(const char* error)
    {
        // Initialize time to default time and raise exception
        this->hour = this->minute = this->second = 0;
        throw error;
    }
    
    // Case valid input - Assign to clock values
    this->hour = h;
    this->minute = m;
    this->second = s;
}


// Methods
// Setters
void Clock::setHour(int h)
{
    // Case invalid input - Raise exception
    if (h < 0 || h > MAX_HOUR)
        throw HOUR_ERROR;
    // Case valid input - Assign to clock
    this->hour = h;
}


void Clock::setMinute(int m)
{
    // Case invalid input - Raise exception
    if (m < 0 || m > MAX_MINUTE)
        throw MINUTE_ERROR;
    // Case valid input - Assign to clock
    this->minute = m;
}


void Clock::setSecond(int s)
{
    // Case invalid input - Raise exception
    if (s < 0 || s > MAX_SECOND)
        throw SECOND_ERROR;
    // Case valid input - Assign to clock
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
    // Output time in HH:MM:SS format
    int h = c.getHour(), m = c.getMinute(), s = c.getHour();
    return os << (h < 10 ? "0" : "") << h << ":"
              << (m < 10 ? "0" : "") << m << ":"
              << (s < 10 ? "0" : "") << s;
}


istream& operator>>(istream& is, Clock& c)
{
    // Read clock values from stream
    is >> c.hour >> c.minute >> c.second;

    // Validate input, If invalid - Raise exception
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