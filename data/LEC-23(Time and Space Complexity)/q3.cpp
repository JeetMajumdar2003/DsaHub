#include <iostream>
using namespace std;

int main()
{
    int iteration = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i *= 2){
        for (int j = 1; j <= i; j++){
            iteration++;
        }
    }
    cout << iteration << endl;
    // Time Complexity is O(n)
    // Space Complexity is O(1)
    // Total Iterations = (2^(log2(n) + 1))-1
    return 0;
}