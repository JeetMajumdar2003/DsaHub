#include <iostream>
using namespace std;

int main()
{
    int iteration = 0, n;
    cin >> n;
    for (int i = 2; i <= n; i *= i){
            iteration++;
    }
    cout << iteration << endl;
    // Time Complexity is O(log(log n))
    // Space Complexity is O(1)
    // Total Iterations = log(log n) + 1
    return 0;
}