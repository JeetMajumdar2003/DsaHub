#include <iostream>
using namespace std;

int main()
{
    int decimal, binary = 0, base = 1, rem;
    cout << "Enter the decimal number: ";
    cin >> decimal;

    // Methode-1:
    while (decimal > 0)
    {
        rem = decimal % 2;
        binary += rem * base;
        decimal /= 2;
        base *= 10;
    }
    cout << "The binary equivalent is: " << binary << endl;

    // Methode-2:
    while (decimal > 0)
    {
        binary = binary * 10 + decimal % 2;
        decimal /= 2;
    }
    cout << "The binary equivalent is: " << binary << endl;

    // Methode-3:
    while (decimal > 0)
    {
        if(decimal % 2 == 0)
            binary = binary * 10 + 0; // or binary *= 10 + 0;
        else
            binary = binary * 10 + 1; // or binary *= 10 + 1;
        decimal /= 2;
    }
    cout << "The binary equivalent is: " << binary << endl;

    // Methode-4:
    while (decimal > 0)
    {
        binary = binary * 10 + ((decimal % 2 == 0) ? 0 : 1);
        decimal /= 2;
    }
    cout << "The binary equivalent is: " << binary << endl;
    return 0;
}