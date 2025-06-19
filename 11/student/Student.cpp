#include "Student.h"

Student::Student(int _id, string fname, string lname)
	:id(_id), firstName(fname), lastName(lname)
{}

ostream& operator<<(ostream& os, const Student& s)
{
	os << "ID:\t" << s.id << endl;
	os << "Name:\t" << s.firstName << ' ' << s.lastName << endl;
	return os;
}

istream& operator>>(istream& is, Student& s)
{
	is >> s.id >> s.firstName >> s.lastName;
	return is;
}