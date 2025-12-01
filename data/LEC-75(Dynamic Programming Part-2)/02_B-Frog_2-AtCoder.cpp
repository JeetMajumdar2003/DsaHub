/** B-Frog 2: 
 * Problem Statement:
 * ------------------
 * There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is h.
 * There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:
 * If the frog is currently on Stone i, jump to one of the following:
 * - Stone i+1
 * - Stone i+2
 * - …
 * - Stone i+K
 * Here, a cost of |hi−hj| will be incurred, where j is the stone to land on.
 * Find the minimum possible total cost incurred before the frog reaches Stone N.
 * 
 * Constraints:
 * ------------
 * 1. 2≤N≤10^5
 * 2. 1≤K≤100
 * 3. 1≤hi≤10^4
 * 
 * Input:
 * ------
 * The first line contains two integers N and K (2≤N≤10^5, 1≤K≤100).
 * The second line contains N integers h1,h2,…,hN (1≤hi≤10^4).
 * 
 * Output:
 * -------
 * Print the minimum possible total cost incurred.
 * 
 * Sample Input:
 * -------------
 * 5 3
 * 10 30 40 50 20
 * 
 * Sample Output:
 * --------------
 * 30
 * 
 * Sample Input:
 * -------------
 * 2 100
 * 10 10
 * 
 * Sample Output:
 * --------------
 * 0
 * 
 * Sample Input:
 * -------------
 * 4 2
 * 10 100 10 100
 * 
 * Sample Output:
 * --------------
 * 90
 * 
 * Resources:
 * https://atcoder.jp/contests/dp/tasks/dp_b
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// DP Vector
vector<int> dp(100001, -1);

// Top-Down DP
int frog2TD(vector<int> &h, int n, int k, int i) {
    // Base Case
    if(i == n-1) {
        return 0;
    }
    // Look-Up(Memoization)
    if(dp[i] != -1) {
        return dp[i];
    }
    // Recursive Case
    int ans = INT_MAX;
    for(int j = 1; j <= k; j++) {
        if(i+j < n) {
            ans = min(ans, abs(h[i]-h[i+j]) + frog2TD(h, n, k, i+j));
        }
    }
    return dp[i] = ans;
}

// Bottom-Up DP(Tabulation)
int frog2BU(vector<int> &h, int n, int k) {
    vector<int> dp(n, INT_MAX);
    // dp[0] = 0;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 1; j <= k; j++) {
    //         if(i+j < n) {
    //             dp[i+j] = min(dp[i+j], dp[i] + abs(h[i]-h[i+j]));
    //         }
    //     }
    // }
    // return dp[n-1];
    dp[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        for(int j = 1; j <= k; j++) {
            if(i+j < n) {
                dp[i] = min(dp[i], abs(h[i]-h[i+j]) + dp[i+j]);
            }
        }
    }
    return dp[0];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    // Top-Down DP
    // cout<<frog2TD(h, n, k, 0)<<endl;

    // Bottom-Up DP
    cout<<frog2BU(h, n, k)<<endl;
    return 0;
}