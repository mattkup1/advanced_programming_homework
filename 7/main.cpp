#include "RoundList.h"
#include <iostream>
using namespace std;

enum CHOICES 
{
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY
};

int main() 
{
	RoundList ls1;
	int choice;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	while (choice != EXIT)
	{
		try
		{		
			int num;
			switch (choice) 
			{
				case ADD: 	
					cout << "Enter 5 numbers: " << endl;
					for (int i = 0; i < 5; i++)
					{
						cin >> num;
						ls1.add(num);
					}
					break;
				case ADD_TO_END:
					cout << "Enter 5 numbers: " << endl;
					for (int i = 0; i < 5; i++)
					{
						cin >> num;
						ls1.addToEnd(num);
					}
					break;
				case REMOVE_FIRST: 
					ls1.removeFirst();
					break;
				case SEARCH: 
					cout << "Enter a number: " << endl;
					cin >> num;
					cout << ls1.search(num) << endl;
					break;
				case CLEAR: 
					ls1.clear();
					break;
				case EMPTY: 
					if (ls1.isEmpty())
					cout << "Empty" << endl;
						else
					cout << "Not empty" << endl;
					break;
				default: 
					cout << "ERROR!" << endl;
			}
		}
		catch (const char* error)
		{
			cout << error << endl;
		}
		cout << "Enter your choice: " << endl;
		cin >> choice;
	}
	return 0;
}

/*
EXAMPLE:

Enter your choice: 
1
Enter 5 numbers: 
6 7 8 9 10
Enter your choice: 
2
Enter 5 numbers: 
5 4 3 2 1
Enter your choice: 
4
Enter a number: 
0
10
Enter your choice: 
3
Enter your choice: 
4
Enter a number: 
0
9
Enter your choice: 
3
Enter your choice: 
4
Enter a number: 
0
8
Enter your choice: 
6
Not empty
Enter your choice: 
5
Enter your choice: 
4
Enter a number: 
2
List empty, Cannot search empty list
Enter your choice: 
6
Empty
Enter your choice: 
1
Enter 5 numbers: 
5 4 3 2 1
Enter your choice: 
4
Enter a number: 
0
1
Enter your choice: 
4
Enter a number: 
1
2
Enter your choice: 
5
Enter your choice: 
0
*/