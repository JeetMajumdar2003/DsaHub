#include <iostream>
using namespace std;

int main()
{
    // Size of an array
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr1);
    cout << n << endl; // 24

    // Length of an array
    int arr2[] = {1, 2, 3, 4, 5};
    int l = sizeof(arr2) / sizeof(arr2[0]);
    cout << l << endl; // 5
    cout << sizeof(arr2) << endl; // 20
    return 0;
}