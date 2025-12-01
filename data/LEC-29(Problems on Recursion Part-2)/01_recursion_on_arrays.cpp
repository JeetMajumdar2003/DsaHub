#include <iostream>
using namespace std;

// function to print array elements using recursion
void printArray(int *arr, int idx, int n)
{
    // base case
    if (idx == n)
        return;

    // self work: print the current element
    cout << arr[idx] << " ";

    // assume that: recursion function to print the remaining elements
    printArray(arr, idx + 1, n);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, 0, n);
    return 0;
}