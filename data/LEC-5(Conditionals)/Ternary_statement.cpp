#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter a number: ";
    cin >> a;

    // Ternary statement:
    (a >= 0) ? cout << "positive." << endl : cout << "negative." << endl;

    // if-else statement:
    if (a >= 0)
        cout << "positive." << endl;
    else
        cout << "negative." << endl;
    return 0;
}