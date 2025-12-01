/** Longest Increasing Subsequence - Leeocode-300
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 * A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.
 * 
 * Example 1:
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 * 
 * Example 2:
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * Explanation: The longest increasing subsequence is [0, 1, 2, 3], therefore the length is 4.
 * 
 * Example 3:
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 * Explanation: The longest increasing subsequence is [7], therefore the length is 1.
 * 
 * Constraints:
 * 1 <= nums.length <= 2500
 * -104 <= nums[i] <= 104
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;

// Top-Down Approach
int lengthOfLISTD(int i, vector<int>& nums){
    if(i == 0) return 1;
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j = 0; j < i; j++){
        if(nums[j] < nums[i]){
            ans = max(ans, 1 + lengthOfLISTD(j, nums));
        }
    }
    return dp[i] = ans;
}

// Bottom-Up Approach
int lengthOfLISTB(vector<int>& nums){
    int n = nums.size();
    dp.clear();
    dp.resize(n, 1);
    int ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int n = nums.size();
    dp.clear();
    dp.resize(n, -1);
    cout << lengthOfLISTD(n-1, nums) << endl;
    cout << lengthOfLISTB(nums) << endl;
    return 0;
}