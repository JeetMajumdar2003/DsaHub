#include <iostream>
using namespace std;

int main()
{
    int iteration = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i *= 2){
        for (int j = n; j > i; j--){
            iteration++;
        }
    }
    cout << iteration << endl;
    // Time Complexity is O(nlog n)
    // Space Complexity is O(1)
    // Total Iterations = n(log n + 1) - (2^(log2(n) + 1))-1
    return 0;
}