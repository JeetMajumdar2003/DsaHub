/** Decode Ways - LeetCode-91
 * A message containing letters from A-Z can be encoded into numbers using the following mapping:
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 * 
 * To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
 * - "AAJF" with the grouping (1 1 10 6)
 * - "KJF" with the grouping (11 10 6)
 * 
 * Given a string s containing only digits, return the number of ways to decode it.
 * The answer is guaranteed to fit in a 32-bit integer.
 * 
 * Constraints:
 * ------------
 * 1. 1 <= s.length <= 100
 * 2. s contains only digits and may contain leading zero(s).
 * 
 * Input:
 * ------
 * A single string s.
 * 
 * Output:
 * -------
 * Return the number of ways to decode it.
 * 
 * Sample Input:
 * -------------
 * "12"
 * 
 * Sample Output:
 * --------------
 * 2
 * 
 * Sample Input:
 * -------------
 * "226"
 * 
 * Sample Output:
 * --------------
 * 3
 * 
 * Sample Input:
 * -------------
 * "0"
 * 
 * Sample Output:
 * --------------
 * 0
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// DP Vector
vector<int> dp;

// Top-Down DP
int numDecodingsTD(string &s, int i) {
    // Base Case
    if(i == s.size()) {
        return 1;
    }
    
    // Lookup
    if(dp[i] != -1) {
        return dp[i];
    }
    
    // Recursive Case
    int ways = 0;
    if(s[i] != '0') {
        ways += numDecodingsTD(s, i+1);
    }
    if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
        ways += numDecodingsTD(s, i+2);
    }
    
    return dp[i] = ways;
}

// Bottom-Up DP
int numDecodingsBU(string &s) {
    dp[s.size()] = 1;
    for(int i = s.size()-1; i >= 0; i--) {
        int ways = 0;
        if(s[i] != '0') {
            ways += dp[i+1];
        }
        if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
            ways += dp[i+2];
        }
        dp[i] = ways;
    }
    return dp[0];
}

int main() {
    string s;
    cin >> s;
    
    
    // Top-Down DP
    dp.resize(s.size()+1, -1);
    cout<<numDecodingsTD(s, 0)<<endl;
    
    // Bottom-Up DP
    dp.resize(s.size()+1, 0);
    cout<<numDecodingsBU(s)<<endl;

    return 0;
}
