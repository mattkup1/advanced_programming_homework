/*
	Name: Matt Kuperwasser 322667270
	Course: Advanced Programming
	Assignment 2, Question 2
	This program tests the RoundVector class
*/

#include<iostream>
#include"RoundVector.h"
using namespace std;

// Function to create a RoundVector and populate it with user input
RoundVector input(int capacity)//global function that returns an object
{
	int numsToInput;//the number to be put in the vec
	RoundVector newObject(capacity);//creates a new object in constructor according to capacity
	cout << "Enter " << capacity << " numbers:" << endl;
	for (int i = 0; i < capacity; i++)//inputs the vec's numbers
	{
		cin >> numsToInput;
		newObject.addNext(numsToInput);//add the numbers to the vec according to the round motion
	}
	return newObject;//returns the new object
}

// Enum to represent user menu options
enum OPTIONS { STOP, TEST1, TEST2, TEST3 };

// Main function to test various functionalities of the RoundVector class
int main()
{
	int choice;
	do // do while coice =! 0
	{
		cout << "Enter your choice 0-3:" << endl; 
		cin >> choice;
		// Handle user choice and run corresponding test
		switch (choice)
		{
		case TEST1:
		{
			// Test constructor and addNext functionality
			cout << "--- Test 1 --- constructor --" << endl;
			RoundVector rv1(4);
			rv1.addNext(10);
			rv1.addNext(11);
			rv1.addNext(12);
			rv1.addNext(13);
			rv1.print();
			rv1.addNext(14);
			rv1.print();
			cout << rv1.firstValue() << endl; //10
			break;
		}
		case TEST2:
		{
			// Test copy constructor and RoundVector operations
			cout << "--- Test 2 --- copy constructor --" << endl;
			RoundVector rv1(4);
			rv1.addNext(10);
			rv1.addNext(11);
			rv1.addNext(12);
			rv1.addNext(13);
			RoundVector rv2(rv1); // Call copy ctor
			rv2.print();
			cout << rv2.firstValue() << endl;
			cout << rv2.removeFirst() << endl;
			rv2.print();
			rv2.addNext(14);
			rv2.print();
			rv2.addNext(15);
			rv2.print();
			cout << rv2.removeFirst() << endl;
			cout << rv2.removeFirst() << endl;
			rv2.print();
			rv2.addNext(15);
			rv2.addNext(16);
			rv2.print();
			rv2.addNext(17);
			cout << rv2.firstValue() << endl;
			break;
		}
		case TEST3:
		{
			// Test move constructor using input function and perform operations
			cout << "--- Test 3 --- move constructor --" << endl;
			RoundVector rv3 = input(6); // Call move ctor
			rv3.print();
			rv3.addNext(7);
			cout << rv3.removeFirst() << endl;
			rv3.print();
			cout << rv3.removeFirst() << endl;
			rv3.print();
			cout << rv3.removeFirst() << endl;
			rv3.print();
			cout << rv3.removeFirst() << endl; 
			rv3.print();
			cout << rv3.removeFirst() << endl;
			rv3.print();
			cout << rv3.removeFirst() << endl;
			if (!rv3.isEmpty())
				rv3.removeFirst();
			rv3.addNext(7);
			rv3.addNext(8);
			cout << rv3.firstValue() << endl;
			rv3.print();
			rv3.clear();
			rv3.addNext(9);
			rv3.addNext(10);
			rv3.addNext(11);
			cout << rv3.firstValue() << endl;
			rv3.print();
			break;
		}
		default : break;
		}
	} while (choice);
	return 0;
}

/*
EXAMPLE:
mattkuperwasser@Mac 2.1 % ./roundVector                                     
Enter your choice 0-3:
2
--- Test 2 --- copy constructor --
in constructor
in copy constructor
10 11 12 13 
10
10
11 12 13 
11 12 13 14 
Vector is full
11 12 13 14 
11
12
13 14 
13 14 15 16 
Vector is full
13
in destructor
in destructor
Enter your choice 0-3:
3
--- Test 3 --- move constructor --
in constructor
Enter 6 numbers:
1
2
3
4
5
6
1 2 3 4 5 6 
Vector is full
1
2 3 4 5 6 
2
3 4 5 6 
3
4 5 6 
4
5 6 
5
6 
6
7
7 8 
9
9 10 11 
in destructor
Enter your choice 0-3:
0
mattkuperwasser@Mac 2.1 %
*/