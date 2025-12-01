#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin >> n;

    if(n%2==0) // scope of conditionals statements is upto 1st semicolon
        cout<<"Even number";
    else
        cout<<"Odd number";
    return 0;
}