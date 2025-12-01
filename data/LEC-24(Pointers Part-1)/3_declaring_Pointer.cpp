#include <iostream>
using namespace std;

int main()
{
    int* ptr;   // only declaring a pointer variable
    
    cout<<ptr<<"\n";  // garbage value

    int x = 25;
    ptr = &x;   // assigning address of x to ptr

    cout<<ptr;  // address of x

    return 0;
}