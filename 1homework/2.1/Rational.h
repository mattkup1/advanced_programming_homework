#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
    private:
         // Declare Numerator and Denominator variables
        int mone;
        int mechane;

    public:
         // Constructor with two parameters at most
         // Initializes a rational number with numerator 'a' and denominator 'b' (Both set by default to 1)
         // Ensures the denominator is always positive
        Rational (int a = 1, int b = 1);

         // Copy Constructor
         // Creates a new Rational object with the same numerator and denominator as the given Rational 'r'
        Rational(const Rational &r);

         // Methods:
         // Setter and Getter for Numerator
        void setMone(int n);
        int getMone() const;

         // Setter and Getter for Denominator
        void setMechane(int n);
        int getMechane() const;

         // Prints the rational number in the format "numerator/denominator"
        void print() const;

         // Checks if two rational numbers are equal
        bool equal(const Rational R) const;

         // Copies the values of the current Rational object to another Rational object 'r'
        void makeEquals(Rational &r) const;
};

#endif // RATIONAL_H