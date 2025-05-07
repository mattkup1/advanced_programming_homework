#include "Worker.h"

int main()
{
    Worker w;
    cout << "Before initialization: " << endl;
    cout << w;
    cout << "Enter worker information: " << endl;
    cin >> w;
    cout << "After initialization: " << endl;
    cout << w;

    return 0;
}