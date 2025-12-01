#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to check one to one mapping from s1 to s2
bool checkOneToOneMapping(string s1, string s2) {
    unordered_map<char, char> map;
    for(int i=0; i<s1.length(); i++) {
        if(map.find(s1[i]) != map.end()) {
            if(map[s1[i]] != s2[i]) return false;
        } else {
            map[s1[i]] = s2[i];
        }
    }
    return true;
}

// Function to check if the given strings are isomorphic
bool checkIsomorphic(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    
    // Check one to one mapping from s1 to s2 and s2 to s1
    bool s1ToS2 = checkOneToOneMapping(s1, s2);
    
    // Check one to one mapping from s2 to s1
    bool s2ToS1 = checkOneToOneMapping(s2, s1);

    // If both mappings are one to one, then the strings are isomorphic
    bool result = s1ToS2 && s2ToS1;

    return result;
}   

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    cout<< (checkIsomorphic(s1, s2)? "Is Isomorphic" : "Is Not Isomorphic") << endl;
    return 0;
}

/*
Time Complexity: O(n)  # n = sum of lengths of s1 and s2
Space Complexity: O(n) # n = unique characters in s1 or s2
*/