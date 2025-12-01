/** Regular Expression Matching: LC-10(https://leetcode.com/problems/regular-expression-matching/)
 * Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * 
 * Example 1:
 * Input: s = "aa", p = "a"
 * Output: false
 * 
 * Example 2:
 * Input: s = "aa", p = "a*"
 * Output: true
 * 
 * Example 3:
 * Input: s = "ab", p = ".*"
 * Output: true
 * 
 * Note:
 * 1. p = "ab.c"
 *    s = "abdc" or "abcc" or "abec" or "abcdc" or "abdc" (. can be replaced by any single character)
 * 
 * 2. p = "ab*c"
 *    s = "abc" or "abcc" or "abbbbc" or "abbbbbbc" (b can be replaced by zero or more b's)
 */

#include <iostream>
#include <vector>
using namespace std;

// Bottom-Up DP
bool isMatchBU(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= m; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
        }
    }

    return dp[n][m];
}

vector<vector<int>> memo;
// Top-Down DP
bool isMatch(string s, string p, int i, int j){
    // Base case:
    if(i == s.size() && j == p.size()) return true;
    if(j == p.size()) return false;

    // Edge case: if there are remaining pattern like "a*" or ".*"
    if (i == s.size()) {
        while (j + 1 < p.size() && p[j + 1] == '*') {
            j += 2;
        }
        return memo[i][j] = (j == p.size());
    }

    // Check if already computed
    if(memo[i][j] != -1) return memo[i][j];

    // Check if the current characters match or if p[j] is '.'
    bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

    // Handle the '*' case
    if(j + 1 < p.size() && p[j + 1] == '*'){
        memo[i][j] = (isMatch(s, p, i, j + 2) || (match && isMatch(s, p, i + 1, j)));
    }
    else {
        memo[i][j] = match && isMatch(s, p, i + 1, j + 1);
    }

    // Store the result in the memoization table
    return memo[i][j];
}

int main() {
    string s = "aa";
    string p = "a*";
    memo.resize(25, vector<int>(25, -1));
    
    cout << "Is Match: (Top-Down DP) " << isMatch(s, p, 0, 0) << endl;
    cout << "Is Match: (Bottom-Up DP) " << isMatchBU(s, p) << endl;


    // Test cases
    // vector<pair<string, string>> testCases = {
    //     {"aa", "a"},    // false
    //     {"aa", "a*"},   // true
    //     {"ab", ".*"},   // true
    //     {"aab", "c*a*b"},   // true
    //     {"mississippi", "mis*is*p*."},   // false
    //     {"ab", ".*c"}    // false
    // };

    // for (const auto& testCase : testCases) {
    //     // Reset memoization table for each test case
    //     memo.resize(testCase.first.size() + 1, vector<int>(testCase.second.size() + 1, -1));

    //     // Test both approaches
    //     cout << "Is Match for s = \"" << testCase.first << "\" and p = \"" << testCase.second << "\": "
    //          << "Top-Down DP: " << isMatch(testCase.first, testCase.second, 0, 0) << ", "
    //          << "Bottom-Up DP: " << isMatchBU(testCase.first, testCase.second) << endl;

    //     // Reset memoization table for the next test case
    //     memo.assign(testCase.first.size() + 1, vector<int>(testCase.second.size() + 1, -1));
    // }

    return 0;
}