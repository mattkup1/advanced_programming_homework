#include <iostream>
#include <string>

using namespace std;

int main()
{
    string email = "matiskuperwasser@gmail.com";

    cout << email.find(".com", 16) << endl;

    cout << "len: " << email.length() << endl;
}