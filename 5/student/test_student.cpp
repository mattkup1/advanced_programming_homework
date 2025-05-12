#include "Student.h"

int main()
{
    cout << "Test 1: Default ctor and output" << endl;
    Student s;
    cout << "Printing new student: " << endl;
    cout << s << endl << endl;

    cout << "Test 2: Input / Output" << endl;
    cout << "Enter student information: (id, first, last, up to 5 courses) ";
    cin >> s;
    cout << "Printing updated student information: " << endl;
    cout << s << endl << endl;

    cout << "Test 3: [] operator: " << endl;
    int course;
    cout << "Enter course id (1-5): " << endl;
    cin >> course;
    cout << (s[course] ? "Signed up" : "Not Signed Up") << endl;

    cout << "Test 4: Assignment ctor" << endl;
    Student st(322667270, "Matt", "Kuperwasser");
    cout << "Printing new student: " << endl;
    cout << st << endl << endl;

    return 0;
}