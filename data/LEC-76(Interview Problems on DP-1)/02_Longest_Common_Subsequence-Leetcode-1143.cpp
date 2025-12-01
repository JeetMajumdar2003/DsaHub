/** Longest Common Subsequence - Leetcode-1143
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 * A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters.
 * (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.
 * If there is no common subsequence, return 0.
 * 
 * Example 1:
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3
 * Explanation: The longest common subsequence is "ace".
 * 
 * Example 2:
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc".
 * 
 * Example 3:
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 * 
 * Constraints:
 * 1 <= text1.length, text2.length <= 1000
 * text1 and text2 consist of only lowercase English characters.
 * 
 * Approach:
 * 1. If the last characters of both strings are same, then the length of LCS(text1, text2) = 1 + LCS(text1-1, text2-1)
 * 2. If the last characters of both strings are different, then the length of LCS(text1, text2) = max(LCS(text1-1, text2), LCS(text1, text2-1))
 * 3. We can solve this problem using DP.
 * 4. Create a 2D array dp of size (text1.size()+1) x (text2.size()+1) and initialize it with 0.
 * 5. Traverse the dp array and fill it using the above approach.
 * 6. The last element of dp array will be the length of LCS(text1, text2).
 * 
 * Complexity Analysis:
 * Time Complexity: O(n*m), where n is the size of text1 and m is the size of text2.
 * Space Complexity: O(n*m), where n is the size of text1 and m is the size of text2.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> dp;

// Top-Down Approach
int longestCommonSubsequenceTD(string t1, string t2, int i, int j){
    // Base Case
    if(i == t1.size() || j == t2.size()){
        return 0;
    }

    // If the last characters of both strings are same
    if(t1[i] == t2[j]){
        return 1 + longestCommonSubsequenceTD(t1, t2, i+1, j+1);
    }
    // If the last characters of both strings are different
    else{
        return max(longestCommonSubsequenceTD(t1, t2, i+1, j), longestCommonSubsequenceTD(t1, t2, i, j+1));
    }
}

// Bottom-Up Approach
int longestCommonSubsequenceBU(string t1, string t2){
    int n = t1.size();
    int m = t2.size();
    dp.resize(n+1, vector<int>(m+1, 0));

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(t1[i] == t2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}

int main(){
    string text1 = "abcde";
    string text2 = "ace";

    // Top-Down Approach
    dp.clear();
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
    cout << longestCommonSubsequenceTD(text1, text2, 0, 0) << endl;

    // Bottom-Up Approach
    cout << longestCommonSubsequenceBU(text1, text2) << endl;
    return 0;
}