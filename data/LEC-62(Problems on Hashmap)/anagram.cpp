#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;

// Function to check if the strings are anagrams
bool anagramCheck(string s1, string s2) {
    unordered_map<char, int> freq;
    for (char c1 : s1) {
        freq[c1]++;
    }
    for (char c2 : s2) {
        if(freq.find(c2) == freq.end()) {
            return false;
        }
        freq[c2]--;
    }
    for (auto it : freq) {
        if (it.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // take two strings as input
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    cout << (anagramCheck(s1, s2) ? "Strings are anagrams" : "Strings are not anagrams") << endl;
    return 0;
}