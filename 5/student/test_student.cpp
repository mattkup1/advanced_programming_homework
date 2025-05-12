#include "Student.h"

int main()
{
    Student s;
    cout << "Printing new student: " << endl;
    cout << s << endl << endl;

    cout << "Enter student information: (id, first, last, up to 5 courses) ";
    cin >> s;
    cout << "Printing updated student information: " << endl;
    cout << s << endl << endl;

    Student st(322667270, "Matt", "Kuperwasser");
    cout << "Printing new student: " << endl;
    cout << st << endl << endl;

    cout << "Testing [] operator: " << endl;
    int course;
    cout << "Enter course id (1-5): " << endl;
    cin >> course;
    cout << (st[course] ? "Signed up" : "Not Signed Up") << endl;

    return 0;
}