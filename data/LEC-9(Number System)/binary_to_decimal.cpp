#include <iostream>
using namespace std;

int main()
{
    int binary, decimal = 0, base = 1, rem;
    cout << "Enter the binary number: ";
    cin >> binary;
    while (binary > 0)
    {
        rem = binary % 10;  // rem is the remainder, we can also use last_digit variable
        decimal += rem * base;
        binary /= 10;
        base *= 2;
    }
    cout << "The decimal equivalent is: " << decimal << endl;
    return 0;
}