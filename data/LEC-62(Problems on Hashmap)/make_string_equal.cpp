#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Function to check if the strings can be made equal
bool canMakeEqual(vector<string>& strings) {
    unordered_map<char, int> freq;
    for (string s : strings) {
        for (char c : s) {
            freq[c]++;
        }
    }
    for (auto it : freq) {
        if (it.second % strings.size() != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strings(n);
    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    cout<< (canMakeEqual(strings) ? "Yes" : "No") << endl;
    
    return 0;
}