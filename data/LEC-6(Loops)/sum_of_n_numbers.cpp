#include <iostream>
using namespace std;

int main()
{
    // Sum of First N natural numbers:
    int num, sum = 0;
    cout<<"Enter a positive integer: ";
    cin>>num;

    // While Loop:
    int i = 0; // Loop Variable
    while(i<=num){
        sum+=i; // sum = sum + i
        i++;
    }

    // For Loop:
    for (int i = 0; i <= num; i++)
        sum+=i;

    // Do While Loop:
    int j = 0;
    do
    {
        sum+=j;
        j++;
    } while (j<=num);

    // Output:
    cout<<"Sum of first "<<num<< " natural numbers is : "<<sum<<endl;
    return 0;
}