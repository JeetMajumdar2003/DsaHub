#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20};
    int *ptr = &arr[0];

    // post increment
    // (*ptr)++;
    // cout << (*ptr) << endl; // 11

    // cout << (*ptr)++ << endl; // 11

    // cout<<arr[0]<<" "<<arr[1]<<endl;   // 12 20

    // pre increment
    ++(*ptr);
    cout << (*ptr) << endl; // 11

    cout << ++(*ptr) << endl; // 12

    cout << arr[0] << " " << arr[1] << endl; // 12 20
    return 0;
}