#include <iostream>
using namespace std;

int main()
{
    float f = 12.3;
    int x = 25;

    void *ptr = &f;
    cout<<ptr<<endl;

    ptr = &x;
    cout<<ptr<<endl;

    // cout<<*ptr<<endl;    // gives an error

    // Type casting 
    int *integerPointer = (int *)ptr;
    cout<<*integerPointer<<endl;


    return 0;
}