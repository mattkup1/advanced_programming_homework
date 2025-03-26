#include "Rational.h"
#include <iostream>
using namespace std;

// RationalMain.cpp
// This program tests the functionality of the Rational class, including constructors, setters, getters,
// equality checks, and assignment operations.

// Main function to demonstrate Rational class features
int main()
{
	int num1, num2, num3;
	char junk;
	
	// Part 1: Test default constructor, setters, and getters
	cout << "part 1.  empty-ctor + set/get" << endl;
	Rational rat1;
	rat1.print();
	cout << endl;
	
	// Read a rational number from user input in the format "numerator/denominator"
	cout << "enter a rational number:" << endl;
	cin >> num1 >> junk >> num2;
	
	rat1.setMone(num1);
	rat1.setMechane(num2);
	cout << "mone: " << rat1.getMone() << endl;
	cout << "mechane: " << rat1.getMechane() << endl;
	rat1.print();
	cout << endl; 

	cout << "enter a rational number:" << endl;
	cin >> num1 >> junk >> num2;
	Rational rat2(num1, num2);
	rat2.print();
	cout << endl;

	Rational rat3(num1);
	rat3.print();
	cout << endl;

	Rational rat4(rat3);
	rat4.print();
	cout << endl;

	// Part 2: Test equality comparison between Rational objects
	cout << "part 2.  equals" << endl;
	if (rat1.equal(rat2))
		cout << "The two numbers are equal" << endl;
	else
		cout << "The two numbers are different" << endl;

	if (rat3.equal(rat4))
		cout << "The two numbers are equal" << endl;
	else
		cout << "The two numbers are different" << endl;
	cout << endl;

	// Part 3: Test makeEquals function to copy values between Rational objects
	cout << "part 3. makeEquals" << endl;
	rat1.makeEquals(rat2);
	rat2.print();
	cout << endl;

	// Part 4: Test assignment operator for Rational objects
	cout << "part 4. assignment" << endl;
	Rational rat5 = rat1;
	rat5.print();
	cout << endl;

	rat2 = rat4;
	rat2.print();
	cout << endl << endl;

	return 0;
}
