#include "School.h"

int main()
{
	School s;
    int x,id;
    cout << "enter 0 to 4\n";
    cin >> x;
    while (x != 0)
    {
        switch (x)
        {
        case 1: s.addStudent();
                break;
        case 2: cout << "enter an id number" << endl;
                cin >> id;
                if (s.search(id))
                    cout << "student is registered\n";
                else
                    cout << "student is not registered\n";
                break;
        case 3:	cout << "enter an id number" << endl;
                cin >> id;
                s.remove(id);
                break;
        case 4:s.print();
                break;
        default: cout << "error\n";
                break;
        }
        cout << "enter 0 to 4\n";
        cin >> x;
    }
        return 0;
}