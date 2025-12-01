#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *ptr = &x;

    cout<<ptr<<endl;

    ptr = ptr + 1;  // ptr++;
    cout<<ptr<<endl;

    return 0;
}