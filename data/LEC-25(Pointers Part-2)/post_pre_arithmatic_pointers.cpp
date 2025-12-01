#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20};
    int *ptr = &arr[0];

    cout<<ptr <<" "<<*ptr<<endl; // 10
    cout<<ptr+1 <<" "<<*(ptr+1)<<endl; // 20

// post increment
    cout<<*ptr++<<endl;   // same as *(ptr++), as ++ has higher precedence than * => ptr = ptr + 1  // 10
    cout<<ptr<<" "<<ptr+1<<endl;

    cout<<arr[0]<<" "<<arr[1]<<endl;   // 10 20
    cout<<*ptr<<" "<<*(ptr+1)<<endl;   // 20 garbage

    return 0;
}