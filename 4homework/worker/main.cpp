#include "WorkersFile.h"
#include <iostream>
using namespace std;

//declarations of help functions 
void Test1();
void Test2();
void Test3();
void Test4();


enum OPTIONS { STOP, TEST1, TEST2, TEST3, TEST4 };

int main()
{
	int choice;
	do
	{
		cout << "Enter your choice 0-5:" << endl;
		cin >> choice;
		switch (choice)
		{
		case TEST1:
			Test1();
			break;
		case TEST2:
			Test2();
			break;
		case TEST3:
			Test3();
			break;
		case TEST4:
			Test4();
			break;
		default:
			break;
		}
	} while (choice);
}


void Test1()
{
	cout << "--- Test 1 --- one Worker operators --" << endl;

	Worker w1;
	cout << "Empty Worker: " << w1;

	cout << "Input first worker details, id name salary:" << endl;
	cin >> w1;

	cout << "First Worker: " << w1;

	w1 += 350.4;
	cout << "Worker after bonus: " << w1;

	Worker w2;
	cout << "Input second worker details, id name salary:" << endl;
	cin >> w2;

	cout << "Second Worker: " << w2;

	
	int id;
	cout << "Input worker id: " << endl;
	cin >> id;
	if (w1 == id)
		cout << "Id of first worker is " << id << endl;
	else
		cout << "Id of first worker is not " << id << endl;

	if (id == w2)
		cout << "Id of second worker is " << id << endl;
	else
		cout << "Id of second worker is not " << id << endl;

	string name;
	cout << "Input worker name: " << endl;
	cin >> name;

	if (name == w1)
		cout << "Name of first worker is " << name << endl;
	else
		cout << "Name of first worker is not " << name << endl;

	if (w2 == name )
		cout << "Name of second worker is " << name << endl;
	else
		cout << "Name of second worker is not " << name << endl;

	cout << "--- End Test 1 -------------" << endl;
}

void Test2()
{
	cout << "--- Test 2 --- cout -- cin --" << endl;

	string name = "Test2.txt";
	WorkersFile wf2(name);

	cout << "Input worker details, id name salary. Into file: " << name << ". press 0 0 0 to end:" << endl;
	cin >> wf2;

	cout << "Output worker list (id name salary). From file: " << name << "" << endl;
	cout << wf2;

	cout << "Input worker details, id name salary. Into file: " << name << ". press 0 0 0 to end:" << endl;
	cin >> wf2;

	cout << "Output worker list (id name salary). From file: " << name << "" << endl;
	cout << wf2;

	cout << "--- End Test 2 -------------" << endl;
}

void Test3()
{
	cout << "--- Test 3 --- operator[] --" << endl;

	string name = "Test3.txt";
	WorkersFile wf3(name);
	Worker w;
	cout << "Input worker details, id name salary. Into file: " << name << ". press 0 0 0 to end:" << endl;
	cin >> wf3;


	int id;
	cout << "Input worker id: " << endl;
	cin >> id;
	w = wf3[id];
	if (w == 0)
		cout << id << " is not found " << endl;
	else
		cout << w << endl;

	cout << "Input worker id: " << endl;
	cin >> id;
	w = wf3[id];
	if (w == 0)
		cout << id << " is not found " << endl;
	else
		cout << w << endl;

	cout << "Input worker name: " << endl;
	cin >> name;
	w = wf3[name];
	if (w == 0)
		cout << name << " is not found " << endl;
	else
		cout << w << endl;
	cout << "Input worker name: " << endl;
	cin >> name;
	w = wf3[name];
	if (w == 0)
		cout << name << " is not found " << endl;
	else
		cout << w << endl;

	cout << "--- End Test 3 -------------" << endl;
}


void Test4()
{
	cout << "--- Test 4 --- operator+= --" << endl;

	string name = "Test4.txt";
	WorkersFile wf4(name);

	cout << "Input worker details, id name salary. Into file: " << name << ". press 0 0 0 to end:" << endl;
	cin >> wf4;

	cout << "Output worker list (id name salary), before bonus. From file: " << name << "" << endl;
	cout << wf4;

	wf4 += 1000;
	cout << "Output worker list (id name salary), after bonus. From file: " << name << "" << endl;
	cout << wf4;

	cout << "--- End Test 4 -------------" << endl;
}


/*
EXAMPLE:

*/
