#include <iostream>
using namespace std;

int main()
{
    int num, lastdigit = 0, new_num = 0;
    cout << "Enter a number: ";
    cin >> num;
    while (num != 0)
    {
        lastdigit = num % 10;
        new_num = new_num * 10 + lastdigit;
        num /= 10;
    }
    cout << "Reverse Number: " << new_num << endl;
    return 0;
}