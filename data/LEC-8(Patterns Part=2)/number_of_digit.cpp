#include <iostream>
using namespace std;

int main()
{
    int num, digit = 0;
    cout<<"Enter a number: ";
    cin>>num;
    while(num != 0){
        digit++;
        num = num/10;
    }
    cout<<"Number of digit: "<<digit<<endl;
    return 0;
}