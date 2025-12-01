#include <iostream>
#include <vector>
using namespace std;

int fib(int n)
{
    // O(n) space complexity-> Fibonacci series
    // int array[n];
    // array[0] = 0;
    // array[1] = 1;
    // if (n == 0 || n == 1)
    //     return n;
    // for (int i = 2; i <= n; i++)
    //     array[i] = array[i - 1] + array[i - 2];
    // return array[n];

    // O(1) space complexity-> Fibonacci series
    int a = 0, b = 1, c;
    if (n == 0 || n == 1)
        return n;
    for (int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;

}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}