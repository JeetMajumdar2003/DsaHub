/** CSES Problem Set - Coin Combinations II
 * ------------------------------------------
 * Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
 * * 2+2+5
 * * 3+3+3
 * * 2+2+2+3
 * 
 * Input
 * -----
 * The first input line has two integers n and x: the number of coins and the desired sum.
 * The second line has n distinct integers c1,c2,…,cn: the value of each coin.
 * 
 * Output
 * ------
 * Print one integer: the number of ways modulo 10^9+7.
 * 
 * Constraints
 * -----------
 * 1 ≤ n ≤ 100
 * 1 ≤ x ≤ 10^6
 * 1 ≤ ci ≤ 10^6
 * 
 * Example
 * -------
 * Input:
 * 4 10
 * 4 1 2 5
 * 
 * Output:
 * 17
 */

#include <iostream>
#include <vector>
using namespace std;

static const int MOD = 1000000007;

// 2D memo for top-down approach
vector<vector<int>> memo;

// Top-Down DP with 2D memo
int coinCombinationsIITD(const vector<int> &coins, int i, int x) {
    // If sum is exactly 0, there's exactly 1 way: use no coins
    if (x == 0) return 1;
    // If sum < 0 or we've run out of coins, no way to form sum
    if (x < 0 || i == 0) return 0;
    // If value already computed, return from memo
    if (memo[i][x] != -1) return memo[i][x];

    // Include the ith coin (note i stays same, x reduces by coins[i-1])
    long long ways = coinCombinationsIITD(coins, i, x - coins[i - 1]);
    // Exclude the ith coin (move to i-1)
    ways += coinCombinationsIITD(coins, i - 1, x);
    ways %= MOD;

    return memo[i][x] = (int)ways;
}


// Bottom-Up DP
int coinCombinationsIIBU(vector<int> &c, int n, int x) {
    // Initialize a dp array with size x+1 and all elements set to 0
    vector<int> dp(x+1, 0);
    // Base case: There is one way to make sum 0, which is to use no coins
    dp[0] = 1;
    
    // Iterate over each coin
    for(int i = 0; i < n; i++) {
        // Update the dp array for all sums that can be achieved using the current coin
        for(int j = 1; j <= x; j++) {
            if(j-c[i] < 0) continue;
            dp[j] = (dp[j] + dp[j-c[i]]) % MOD;
        }
    }
    // Return the number of ways to make sum x
    return dp[x];
}

int main() {
    // Input
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    // Top-Down DP
    // Initialize the 2D memo to -1, meaning "not computed"
    memo.assign(n + 1, vector<int>(x + 1, -1));
    cout << coinCombinationsIITD(c, n, x) << endl;

    // Bottom-Up DP
    cout << coinCombinationsIIBU(c, n, x) << endl;
    return 0;
}
// Time Complexity: O(n*x)
// Space Complexity: O(x)

/**Deepseek
 * ---------
 * #include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>> dp; // 2D DP for memoization: dp[n][x]

int coinCombinationsTD(vector<int>& coins, int n, int x) {
    // Base Cases
    if (x == 0) return 1; // Valid combination found
    if (x < 0 || n == 0) return 0; // Invalid combination or no coins left
    
    // Check if already computed
    if (dp[n][x] != -1) return dp[n][x];
    
    // Include the nth coin (coins[n-1]) and stay at 'n' (unbounded)
    int include = coinCombinationsTD(coins, n, x - coins[n - 1]);
    // Exclude the nth coin, move to 'n-1' coins
    int exclude = coinCombinationsTD(coins, n - 1, x);
    
    // Memoize and return
    return dp[n][x] = (include + exclude) % MOD;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    
    // Initialize DP table with -1 (n+1 rows, x+1 columns)
    dp.resize(n + 1, vector<int>(x + 1, -1));
    
    cout << coinCombinationsTD(coins, n, x) << endl;
    return 0;
}
 */