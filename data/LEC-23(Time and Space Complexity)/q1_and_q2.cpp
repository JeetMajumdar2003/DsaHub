#include <iostream>
using namespace std;

int main()
{
    // Time Complexity is O(log n)
    // Space Complexity is O(1)
    // Total Iterations = (log2(n) + 1)
    int iteration = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i *= 2){
        iteration++;
    }
    cout << iteration << endl;
    
    return 0;
}