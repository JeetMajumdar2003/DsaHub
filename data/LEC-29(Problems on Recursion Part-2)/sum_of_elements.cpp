#include <iostream>
using namespace std;

// function to print array elements using recursion
int sumArray(int *arr, int idx, int n)
{
    // base case
    if (idx == n-1)
        return arr[idx];

    // assume that: recursion function to find sum of the remaining array elements
    // self work: return the sum
    return (arr[idx] + sumArray(arr, idx+1, n));
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = sumArray(arr, 0, n);
    cout<<result;
    return 0;
}