#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // even and divisible by 3
    if (num % 2 == 0 || num % 3 == 0)  // divisible by 3 or 5
        cout << "The number is divisible by either 3 or 5." << endl;
    return 0;
}