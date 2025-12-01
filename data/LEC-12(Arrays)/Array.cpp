#include <iostream>
using namespace std;

int main()
{
    // Array declaration by specifying size
    int arr1[3];
    // Insert Element in an Array
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    // Accessing elements of an array
    cout << arr1[0] << " ";
    cout << arr1[1] << " ";
    cout << arr1[2] << " ";
    cout << endl;

    // With recent C/C++ versions, we can also  declare an array of user specified size like this
    int n = 5;
    int arr2[n];
    // Accessing elements of an array
    cout << arr2[0] << " "; // Garbage Value
    cout << arr2[1] << " "; // Garbage Value
    cout << arr2[2] << " "; // Garbage Value
    cout << arr2[3] << " "; // Garbage Value
    cout << arr2[4] << " "; // Garbage Value
    cout << endl;

    return 0;
}