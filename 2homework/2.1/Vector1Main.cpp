#include<iostream>
#include"RoundVector.h"
using namespace std;
RoundVector input (int capacity)//global function that returns an object
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
enum OPTIONS { STOP, TEST1, TEST2, TEST3 };
int main()
{
	int choice;
	do
	{
		cout << "Enter your choice 0-3:" << endl; 
		cin >> choice;
		switch (choice)
		{
		case TEST1:
		{
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
			cout << "--- Test 2 --- copy constructor --" << endl;
			RoundVector rv1(4);
			rv1.addNext(10);
			rv1.addNext(11);
			rv1.addNext(12);
			rv1.addNext(13);
			RoundVector rv2(rv1);
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
			cout << "--- Test 3 --- move constructor --" << endl;
			RoundVector rv3 = input(6);
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