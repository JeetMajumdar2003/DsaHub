#include <iostream>
#include <string>

using namespace std;

// Brute force approach: Time complexity: O(n^2), Space complexity: O(1)
int longestOnesBF(string str, int k) {
    int maxLength = 0;
    for (int i = 0; i < str.length(); i++) {
        int zeroCount = 0;
        for (int j = i; j < str.length(); j++) {
            if (str[j] == '0') {
                zeroCount++;
            }
            if (zeroCount <= k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

// Sliding window approach: Time complexity: O(n), Space complexity: O(1)
// function to find the longest substring of 1's in a binary string
int longestOnes(string str, int k) {
    int start = 0;
    int end = 0;
    int zeroCount = 0;
    int maxLength = 0;
    while (end < str.length()) {
        // if the current character is 0, then increment the count of zeros in the current window
        if (str[end] == '0') {
            zeroCount++;
        }
        // if the number of zeros in the current window is greater than k, then shrink the window from the left
        while (zeroCount > k) {     // we can also use if instead of while here
            if (str[start] == '0') {
                zeroCount--;
            }
            start++;
        }

        maxLength = max(maxLength, end - start + 1);
        end++;
    }

    return maxLength;
}

int main() {
    int k;
    cout << "Enter k: ";
    cin >> k;
    string str;
    cout << "Enter the binary string: ";
    cin >> str;

    cout << "The longest substring length of 1's in the binary string is: " << longestOnesBF(str, k) << endl;
    cout << "The longest substring length of 1's in the binary string is: " << longestOnes(str, k) << endl;
    
    return 0;
}
