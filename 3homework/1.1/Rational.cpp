#include <iostream>

// Implementation of the Rational class
// Provides functionality for rational numbers including constructors, getters, setters, and comparison
#include "Rational.h"


// Global recursive function that computes and returns the greatest common denominator for 2 given numbers
int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

                    ////////////////////////// Constructors //////////////////////////////
// Default ctor
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

    return;
}


// Copy ctor
Rational::Rational(const Rational& r)
    : mone(r.mone), mechane(r.mechane)
{}


// Move ctor
Rational::Rational(Rational&& src)
    : mone(src.mone), mechane(src.mechane)
{}


                    //////////////////////////// Methods /////////////////////////////
// Setter for numerator
void Rational::setMone(int n)
{
    this->mone = n;
    return;
}


// Setter for denominator
// Ensures the denominator is always positive
// If given a negative value, adjusts both numerator and denominator accordingly
// If zero is given, sets denominator to 1 to prevent division by zero
void Rational::setMechane(int n)
{
    // Use the already implemented '=' operator and the default ctor
    // To handle the different cases (such as n <= 0)
    *this = Rational(this->mone, n);
}


// Private member function to reduce the fraction
Rational& Rational::reduce() 
{  
    // Case numerator is zero
    if (this->mone == 0)
    {
        this->mechane = 1;
        return *this;
    }
    else if (this->mechane == 0)
    {
        this->mone = this->mechane = 1;
        return *this;
    }
    // Reduce the fraction by greatest common denominator
    int gcd_ = gcd(abs(this->mone), abs(this->mechane));
    // Use the already implemented '=' operator and default ctor
    // To assign the reduced fraction to caller
    // And handle special cases (denominator <= 0)
    *this = Rational(this->mone / gcd_, this->mechane / gcd_);
    // Return reduced fraction
    return *this;
}   


// Prints the rational number in the format "numerator/denominator"
void Rational::print() const
{
    if (this->mechane == 1)
    {
        cout << this->mone;
        return;
    }

    cout << this->mone << "/" << this->mechane;
    return;
}
 

                        //////////////////////// Operators //////////////////////////
// Assignment = 
Rational& Rational::operator=(const Rational& src) 
{
    this->mone = src.getMone();
    this->mechane = src.getMechane();
    return *this;
}


// Addition
Rational Rational::operator+(const Rational& src)
{
    const int newMone = (this->mone * src.getMechane()) + (src.getMone() * this->mechane);
    const int newMechane = this->mechane * src.getMechane();
    Rational result(newMone, newMechane);
    return result.reduce();
}


// Addition assignment +=
Rational& Rational::operator+=(const Rational& src)
{
    // Add by using the already implemented '+' operator
    *this = *this + src;
    return *this;
}


// Subtraction
Rational Rational::operator-(const Rational& src)
{
    // Subtract by adding the negative of src to caller (*this + (-src))
    // Use the already implemented '+=' assignment operator
    Rational result(src.getMone(), -src.getMechane());
    result += *this;
    return result;
}


// Subtraction assignment -=
Rational& Rational::operator-=(const Rational& src)
{
    // Subtract by using the already implemented '-' operator
    *this = *this - src;
    return *this;
}


// Multiplication *
Rational Rational::operator*(const Rational& src)
{
    Rational result(this->mone * src.getMone(), this->mechane * src.getMechane());
    return result.reduce();
}


// Multiplication assignment *=
Rational& Rational::operator*=(const Rational& src)
{
    // Use already implemented '*' operator
    *this = *this * src;
    return *this;
}


// Devision /
Rational Rational::operator/(const Rational& src)
{
    // Use already implemented '*' operator
    Rational result(this->mone * src.getMechane(), this->mechane * src.getMone());
    return result.reduce();
}


// Devision assignment /=
Rational& Rational::operator/=(const Rational& src)
{
    // Use already implemented '/' operator
    *this = *this / src;
    return *this;
}


// ++ Rational
Rational& Rational::operator++()
{
    // Use already implemented '+=' operator
    this->mone += this->mechane;
    return this->reduce();
}


// Rational ++
Rational Rational::operator++(int dummy)
{
    // Use already implemented left side '++' operator
    Rational tmp(*this);
    ++*this;
    return tmp;
}


// -- Rational
Rational& Rational::operator--()
{
    // Use already implemented '-=' operator
    this->mone -= this->mechane;
    return this->reduce();
}


// Rational --
Rational Rational::operator--(int dummy)
{
    // Use already implemented left side '--' operator
    Rational tmp(*this);
    --*this;
    return tmp;
}


                        ////////////////////////// Comparison /////////////////////////////
// Equality ==
// Compares reduced rationals
bool Rational::operator==(const Rational& r) const
{
    Rational a(this->getMone(), this->getMechane()), b(r.getMone(), r.getMechane());
    a.reduce(), b.reduce();
    return (a.getMone() == b.getMone() && a.getMechane() == b.getMechane());
}


// Not Equal !=
bool Rational::operator!=(const Rational& r) const 
{
    // Use already implemented '==' operator
    return !(*this == r);
}


// Less than <
bool Rational::operator<(const Rational& r) const 
{
    // Use constructor in order to get normalized and reduced rationals for comparison
    Rational a(this->getMone(), this->getMechane());
    Rational b(r.getMone(), r.getMechane());
    
    // Return equality state upon multiplying each numerator by opponents denominator
    // For common denominator
    return (a.getMone() * b.getMechane() < b.getMone() * a.getMechane());
}


// From this point on, All further comparison operators can be implemented by
// Use of 2 of the above operators (==, <) or (!=, <)

// Less than or equal to <=
bool Rational::operator<=(const Rational& r) const 
{
    return (*this < r || *this == r);
}


// Greater then >
bool Rational::operator>(const Rational& r) const
{
    return !(*this <= r);
}


// Greater than or equal to >=
bool Rational::operator>=(const Rational& r) const 
{
    return !(*this < r);
}


