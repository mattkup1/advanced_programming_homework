#pragma once

#include <iostream>

using namespace std;

const int MAX_HOUR = 23, MAX_MINUTE = 59, MAX_SECOND = 59;

extern const char* HOUR_ERROR;
extern const char* MINUTE_ERROR;
extern const char* SECOND_ERROR;

class Clock
{
public:
    // default ctor
    Clock() : hour(0), minute(0), second(0) {}
    // Assignment ctor
    Clock(int, int, int);

    // Methods
    // Getters
    int getHour() const { return this->hour; }
    int getMinute() const { return this-> minute; }
    int getSecond() const { return this->second; }
    // Setters
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // Operators
    // Add number of argumented seconds to clock time
    Clock& operator+=(int);
    // Output << operator
    friend ostream& operator<<(ostream&, const Clock&);
    // Input >> operator
    friend istream& operator>>(istream&, Clock&);

private:
    int hour = 0;
    int minute = 0;
    int second = 0;
};