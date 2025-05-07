#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational
{
private:
     // Declare Numerator and Denominator variables
     int mone;
     int mechane;

     // Function to reduce the fraction
     Rational& reduce();

public:
     // Default ctor
     Rational (int a = 1, int b = 1);
     // Copy ctor
     Rational(const Rational &src);
     // Move ctor
     Rational(Rational &&src);

     // Methods:
     // Setter and Getter for Numerator
     void setMone(int n);
     int getMone() const { return this->mone; }
     // Setter and Getter for Denominator
     void setMechane(int n);
     int getMechane() const { return this->mechane; }
     // Print function
     void print() const;

     // Operators
     Rational& operator=(const Rational&);   // Assignment
     Rational& operator=(Rational&&);        // Move Assignment
     Rational operator+(const Rational&);
     Rational& operator+=(const Rational&);
     Rational operator-(const Rational&);
     Rational& operator-=(const Rational&);
     Rational operator*(const Rational&);
     Rational& operator*=(const Rational&);
     Rational operator/(const Rational&);
     Rational& operator/=(const Rational&);
     Rational& operator++();
     Rational operator++(int);
     Rational& operator--();
     Rational operator--(int);

     // Comparison
     // Can't use const for function and argument as the reduce function is applied
     bool operator==(const Rational&) const;
     bool operator!=(const Rational&) const;
     bool operator<(const Rational&) const;
     bool operator<=(const Rational&) const;
     bool operator>(const Rational&) const;
     bool operator>=(const Rational&) const;
};

#endif // RATIONAL_H