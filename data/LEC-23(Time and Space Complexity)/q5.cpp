#include <iostream>
using namespace std;

int main()
{
    int iteration = 0, n;
    cin >> n;
    for (int i = n; i > 0; i /= 2){ // i>0 => i>=1
        for (int j = 0; j < i; j++){
            iteration++;
        }
    }
    cout << iteration << endl;
    // Time Complexity is O(n)
    // Space Complexity is O(1)
    // Total Iterations = (n(2^(log2(n) + 1))-1)/2^(log2(n))    if n is multiple of 2
    return 0;
}