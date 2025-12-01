#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // even and divisible by 3
    if (num % 2 == 0 && num % 3 == 0)
        cout << "The number is even and divisible by 3." << endl;

    // OR-> the number is also divisible by 6
    if(num%6==0)
        cout << "The number is also divisible by 6." << endl;
    return 0;
}