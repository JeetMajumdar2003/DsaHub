#include <iostream>
#include <vector>
using namespace std;

// Top Down Approach(Memoization): Bigger to Smaller Subproblems
// House Rob
vector<int> dp;
int f(int i, vector<int> &arr){
    // Base Case
    if (i >= arr.size())
        return 0;

    // Check if the value is already computed
    if (dp[i] != -1)
        return dp[i];

    // Recursive Case: Compute the value and store it in dp array, then return it
    return dp[i] = max(arr[i] + f(i + 2, arr), f(i + 1, arr));
}

// Bottom Up Approach(Tabulation): Smaller to Bigger Subproblems
int fbu(vector<int> &arr){
    vector<int> dp(arr.size() + 2, 0);
    for (int i = arr.size() - 1; i >= 0; i--)
        dp[i] = max(arr[i] + dp[i + 2], dp[i + 1]);
    return dp[0];
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    dp.resize(nums.size() + 10, -1);
    cout << f(0, nums)<<"\n"; // Top Down Approach
    cout << fbu(nums); // Bottom Up Approach
    return 0;
}