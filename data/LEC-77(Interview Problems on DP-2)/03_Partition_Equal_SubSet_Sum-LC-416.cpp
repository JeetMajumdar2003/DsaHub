/** Partition Equal Sub Set Sum Problem
 * This problem aims to determine if the given set can be partitioned into two subsets 
 * such that the sum of elements in both subsets is the same.
 * 
 * Example:
 * Input: nums = [1, 5, 11, 5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * Constraints:
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 1000
 * The sum of nums is even.
 * 
 * Approach:
 * 1. Calculate the total sum of the array.
 * 2. If the total sum is odd, return false.
 * 3. Initialize a 2D DP array of size (n+1) x (sum/2+1).
 * 4. Fill the DP array using the bottom-up approach.
 * 5. Return the value at DP[n][sum/2].
 * Time Complexity: O(n * sum)
 * Space Complexity: O(n * sum)
 */

#include <iostream>
#include <vector>
using namespace std;

// Top Down Approach
bool canPartitionUtil(vector<int>& nums, int i, int k, vector<vector<int>>& dp) {
    if (k < 0 || i >= nums.size()) return false;
    if (k == 0) return true;

    if (dp[i][k] != -1) return dp[i][k];

    bool notTake = canPartitionUtil(nums, i + 1, k, dp);
    bool take = false;
    if (nums[i] <= k) {
        take = canPartitionUtil(nums, i + 1, k - nums[i], dp);
    }

    return dp[i][k] = take || notTake;
}

// Bottom Up Approach
bool dpBottomUp(vector<int>& nums, int k, int n) {
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

    // Base case: If required sum(k) is 0, we can always achieve it by not taking any elements.
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= k; j++) {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (nums[i] <= j) {
                take = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = take || notTake;
        }
    }
    return dp[0][k];
}


int main() {
    vector<int> nums = {1, 5, 11, 5};
    int n = nums.size();
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    if (totalSum % 2 != 0) return false;

    int k = totalSum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    // Top Down Approach
    bool resultTopDown = canPartitionUtil(nums, 0, k, dp);
    cout << "Top Down Result: " << resultTopDown << endl;

    // Bottom Up Approach
    bool resultBottomUp = dpBottomUp(nums, k, n);
    cout << "Bottom Up Result: " << (resultBottomUp ? "true" : "false") << endl;

    return 0;
}