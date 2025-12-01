#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cout<<"Enter a positive integer: ";
    cin>>n;
    do{
        int num;
        cout<<"Enter a number to add: ";
        cin>>num;
        sum += num;
        n--;
    } while(n>0);
    cout<<"Sum = "<<sum<<endl;
    return 0;
}