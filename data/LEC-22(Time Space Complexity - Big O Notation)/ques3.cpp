#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int n = 5;
    int arr2[] = {1, 5, 4, 6, 7, 8, 9, 10};
    int m = 8;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        sum1 += arr1[i];
    }
    for (int i = 0; i < m; i++) // O(m)
    {
        sum2 += arr2[i];
    }
    cout << sum1 << " " << sum2 << endl;
    return 0;
}