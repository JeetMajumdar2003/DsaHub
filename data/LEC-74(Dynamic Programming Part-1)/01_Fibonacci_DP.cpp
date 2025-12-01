#include<iostream>
#include<vector>
using namespace std;


// Top Down Approach(Memoization): Bigger to Smaller Subproblems
// Fibonacci using Dynamic Programming(Recursion + Memorization)
int fib_memoisation(int n, vector<int> &dp){
    // Base Case
    if(n==0 || n==1){
        return n;
    }

    // Check if the value is already computed
    if(dp[n] != -1){
        return dp[n];
    }

    // Recursive Case: Compute the value
    int ans = fib_memoisation(n-1, dp) + fib_memoisation(n-2, dp);
    // Store the computed value in the dp array
    dp[n] = ans;
    return ans;
}

// Bottom Up Approach(Tabulation): Smaller to Bigger Subproblems
// Fibonacci using Dynamic Programming(Iterative)
int fib_tabulation(int n, vector<int> &dp){
    dp.resize(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Bottom Up Approach(Tabulation) Optimized Space:
int fib_optimized(int n){
    if(n==0 || n==1){
        return n;
    }

    int a = 0;
    int b = 1;
    int c;
    for(int i=2; i<=n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<fib_memoisation(n, dp)<<endl;
    cout<<fib_tabulation(n, dp)<<endl;
    cout<<fib_optimized(n)<<endl;
    return 0;
}