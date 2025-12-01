#include <iostream>
using namespace std;

int main()
{
    int n, factorial = 1;
    cout<<"Enter a number: ";
    cin>>n;

    // Multiplying the factorial of each number from 1 to n:
    for (int i = 1; i <= n; i++)
    {
        factorial*=i;
        cout<<"Factorial of "<<i<<" is : "<<factorial<<endl;
    }
    return 0;
}