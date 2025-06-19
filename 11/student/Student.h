#pragma once

#include<iostream>
#include<string>
using namespace std;


class Student
{
protected:
	int id;
	string firstName;
	string lastName;

public:
	Student(int id = 0, string fname = "", string lname = "");
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&,  Student&);
};
