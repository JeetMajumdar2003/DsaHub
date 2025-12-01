#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Check if it is possible to make a palindrome or not
bool isPossible(unordered_map<char, int> &mp) {
    int odd = 0;
    for(auto it : mp) {
        if(it.second % 2 != 0) {
            odd++;
        }
    }
    return odd <= 1;
}

// Find the maximum palindrome permutation
string maxPalindromePermutation(string s) {
    int n = s.size();
    unordered_map<char, int> mp;
    for(int i = 0; i < n; i++) {
        mp[s[i] - '0']++;
    }
    if(!isPossible(mp)) {
        return "-1";
    }
    string res = "";
    res.resize(n);
    int pos = 0;
    for(int i = 9; i >= 0; i--) {
        // First add the odd frequency characters
        if(mp[i] % 2 != 0) {
            res[n / 2] = char(i + '0');
            mp[i]--;
        }
        // Now add the remaining even frequency characters
        while(mp[i] > 0) {
            res[pos] = char(i + '0');
            res[n - pos - 1] = char(i + '0');
            pos++;
            mp[i] -= 2;
        }   
    }
    return res;
}

int main() {
    string s = "3132132";
    cout << maxPalindromePermutation(s) << endl; // 321123
    return 0;
}