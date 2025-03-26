#include <iostream>

// Implementation of the Rational class
// Provides functionality for rational numbers including constructors, getters, setters, and comparison
#include "Rational.h"

using namespace std;

// Constructor with two parameters
// Initializes a rational number with numerator 'a' and denominator 'b' (Both set by default to 1)
// Ensures the denominator is always positive
Rational::Rational(int a, int b)
{
    if (b > 0)
    {
        mone = a;
        mechane = b;
    }
    else if (b < 0)
    {
        mone = -a;
        mechane = -b;
    }
    else if (b == 0) 
    { 
        mone = a; 
        mechane = 1;
    }
    else
    {
        cout << "ERROR" << endl;
        mone = mechane = 1;
    }

    cout << "in constructor" << endl;

    return;
}

// Copy Constructor
// Creates a new Rational object with the same numerator and denominator as the given Rational 'r'
Rational::Rational(const Rational &r)
{
    mone = r.mone, mechane = r.mechane;

    cout << "in copy constructor" << endl;
}

 // Setter for numerator
 // Sets the numerator to the given value 'n'
void Rational::setMone(int n)
{
    mone = n;
    return;
}

 // Getter for numerator
 // Returns the current value of the numerator
int Rational::getMone() const
{
    return mone;
}

 // Setter for denominator
 // Ensures the denominator is always positive
 // If given a negative value, adjusts both numerator and denominator accordingly
 // If zero is given, sets denominator to 1 to prevent division by zero
void Rational::setMechane(int n)
{
    if (n > 0)
    {
        mechane = n;
    }
    else if (n < 0)
    {
        mone = -mone;
        mechane = -n;
    }
    else if (n == 0) 
    {
        mechane = 1;
    }
    
    return;
}

 // Getter for denominator
 // Returns the current value of the denominator
int Rational::getMechane() const
{
    return mechane;
}

 // Prints the rational number in the format "numerator/denominator"
void Rational::print() const
{
    cout << mone << "/" << mechane << endl;
    return;
}

 // Checks if two rational numbers are equal
 // Returns true if both numerator and denominator are the same
bool Rational::equal(const Rational R) const
{
    return (R.mone == this->mone and R.mechane == this->mechane);
}

 // Copies the values of the current Rational object to another Rational object 'r'
void Rational::makeEquals(Rational &r) const
{
    r.mone = this->mone, r.mechane = this->mechane;
    return;
}
