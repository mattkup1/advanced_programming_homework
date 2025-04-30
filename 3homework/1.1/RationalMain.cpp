#include"Rational.h"
#include <iostream>
using namespace std;

enum OPERATOR {
	EXIT, ADD_PRE, ADD_POST, SUB_PRE, SUB_POST, ADD, SUB, MULT, DIV,
	ADD_ASSIGN, SUB_ASSIGN, MULT_ASSIGN, DIV_ASSIGN,
	GREATER, LESS_THAN, GREATER_OR_EQUAL, LESS_OR_EQUAL, EQUAL, NOT_EQUAL
};
int main()
{
	int mone, mechane;
	char junk;
	int op;
	cout << "enter your choice:" << endl;
	cin >> op;
	Rational r2, r3;
	while (op != EXIT) {
		cout << "enter a rational number:" << endl;
		cin >> mone >> junk >> mechane;
		Rational r1(mone, mechane);
		if (op >= 5) {
			cout << "enter a rational number:" << endl;
			cin >> mone >> junk >> mechane;
			r2.setMone(mone);
			r2.setMechane(mechane);
		}
		switch (op) {
		case ADD_PRE:
			cout << "x = ++y;" << endl;
			cout << "before operation y is: ";
			r1.print();
			r3 = ++r1;
			cout << endl;/////
			cout << "after operation x is: ";
			r3.print();
			cout << endl << "y is: ";
			r1.print();
			break;
		case ADD_POST:
			cout << "x = " << " y++;" << endl;
			cout << "before operation y is: ";
			r1.print();
			r3 = r1++;
			cout << endl;/////

			cout << "after operation x is: ";
			r3.print();
			cout << endl << "y is: ";
			r1.print();
			break;
		case SUB_PRE:
			cout << "x = --y;" << endl;
			cout << "before operation y is: ";
			r1.print();
			r3 = --r1;
			cout << endl;/////

			cout << "after operation x is: ";
			r3.print();
			cout << endl << "y is: ";
			r1.print();
			break;
		case SUB_POST:
			cout << "x = " << " y--;" << endl;
			cout << "before operation y is: ";
			r1.print();
			r3 = r1--;
			cout << endl;/////

			cout << "after operation x is: ";
			r3.print();
			cout << endl << "y is: ";
			r1.print();
			break;
		case ADD:
			r3 = r1 + r2;
			r1.print();
			cout << " + ";
			r2.print();
			cout << " = ";
			r3.print();
			break;
		case SUB:
			r3 = r1 - r2;
			r1.print();
			cout << " - ";
			r2.print();
			cout << " = ";
			r3.print();
			break;
		case MULT:
			r3 = r1 * r2;
			r1.print();
			cout << " * ";
			r2.print();
			cout << " = ";
			r3.print();
			break;
		case DIV:
			r3 = r1 / r2;
			r1.print();
			cout << " / ";
			r2.print();
			cout << " = ";
			r3.print();
			break;
		case ADD_ASSIGN:
			r1.print();
			cout << " += ";
			r1 += r2;
			r2.print();
			cout << " changes r1 to be: ";
			r1.print();
			break;
		case SUB_ASSIGN:
			r1.print();
			cout << " -= ";
			r1 -= r2;
			r2.print();
			cout << " changes r1 to be: ";
			r1.print();
			break;
		case MULT_ASSIGN:
			r1.print();
			cout << " *= ";
			r1 *= r2;
			r2.print();
			cout << " changes r1 to be: ";
			r1.print();
			break;
		case DIV_ASSIGN:
			r1.print();
			cout << " /= ";
			r1 /= r2;
			r2.print();
			cout << " changes r1 to be: ";
			r1.print();
			break;
		case GREATER:
			r1.print();
			cout << " > ";
			r2.print();
			cout << " ? ";
			if (r1 > r2)
				cout << "yes\n";
			else
				cout << "no\n";
			break;
		case LESS_THAN:
			r1.print();
			cout << " < ";
			r2.print();
			cout << " ? ";
			if (r1 < r2)
				cout << "yes\n";
			else
				cout << "no\n";
			break;
		case GREATER_OR_EQUAL:
			r1.print();
			cout << " >= ";
			r2.print();
			cout << " ? ";
			if (r1 >= r2)
				cout << "yes\n";
			else
				cout << "no\n";
			break;
		case LESS_OR_EQUAL:
			r1.print();
			cout << " <= ";
			r2.print();
			cout << " ? ";
			if (r1 <= r2)
				cout << "yes\n";
			else
				cout << "no\n";
			break;
		case EQUAL:
			r1.print();
			cout << " == ";
			r2.print();
			cout << " ? ";
			if (r1 == r2)
				cout << "yes\n";
			else
				cout << "no\n";
			break;
		case NOT_EQUAL:
			r1.print();
			cout << " != ";
			r2.print();
			cout << " ? ";
			if (r1 != r2)
				cout << "yes\n";
			else
				cout << "no\n";
			break;
		}
		cout << endl;///
		cout << "enter your choice : " << endl;
		cin >> op;
	}
	return 0;
}