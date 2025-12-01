/** Unique Binary Search Tree: LeetCode 96
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * * Example:
 * For n = 3, there are 5 unique BSTs:
 *   1      3       3      2      1
 *    \    /       /       / \      \
 *     3  2       1      1   2      2
 *    /      \       \                 \
 *   2        1       2                 3
 * 
 * The number of unique BSTs can be calculated using dynamic programming or Catalan numbers.
 * 
 * Approach:
 * - Create a DP array where dp[i] represents the number of unique BSTs that can be formed with i nodes.
 * - Initialize dp[0] = 1 and dp[1] = 1.
 * - For each number of nodes from 2 to n, calculate the number of unique BSTs by considering each node as the root.
 * 
 * Implementation:
 * - Define a function uniqueBSTs(int n) that returns the count of unique BSTs for n nodes.
 * - Use nested loops to fill the dp array based on previous values.
 * 
 * Catalans Number: C(n) = (2n)! / ((n + 1)! * n!)
 * C(n) = C(0) * C(n-1) + C(1) * C(n-2) + ... + C(n-1) * C(0)
 */

#include <iostream>
#include <vector>
using namespace std;

// Bottom-Up DP
int uniqueBSTs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int nodes = 2; nodes <= n; ++nodes) {
        for (int root = 1; root <= nodes; ++root) {
            dp[nodes] += dp[root - 1] * dp[nodes - root];
        }
    }

    return dp[n];
}

vector<int> dp(100, -1);
// Top-Down DP
int countBSTsTD(int n) {
    if (n <= 1) return 1;
    if(n == 2) return 2;

    // Check if already computed
    if (dp[n] != -1) return dp[n];

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        count += countBSTsTD(i - 1) * countBSTsTD(n - i);
    }
    
    dp[n] = count;
    return count;
}

int main() {
    int n = 3;

    cout << "Number of unique BSTs for n = " << n << " (Bottom-Up DP): " << uniqueBSTs(n) << endl;
    cout << "Number of unique BSTs for n = " << n << " (Top-Down DP): " << countBSTsTD(n) << endl;
}