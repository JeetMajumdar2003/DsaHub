#include <iostream>
using namespace std;

// function to print array elements using recursion
int maxElement(int *arr, int idx, int n)
{
    // base case
    if (idx == n-1)
        return arr[idx];

    // assume that: recursion function to find max of the remaining array
    // self work: return the max element
    return max(arr[idx], maxElement(arr, idx+1, n));
}

int main()
{
    int arr[] = {10, 12, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxElement(arr, 0, n);
    cout<<result;
    return 0;
}