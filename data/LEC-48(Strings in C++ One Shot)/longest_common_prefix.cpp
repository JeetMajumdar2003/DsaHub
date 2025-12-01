#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


string longestCommonPrefix(vector<string> &str){

    // M-1: Sort the strings and compare the first and last string:    Time: O(nlogn * m), Space: O(min(s[0].size(), s[n-1].size()))
    // sort(str.begin(), str.end());

    // // select the first and last string:
    // string s1 = str[0];
    // string s2 = str[str.size()-1];
    // int i=0, j=0;
    // string ans = "";
    // while (i<s1.size() && j<s2.size())
    // {
    //     if(s1[i] == s2[j]){
    //         ans += s1[i];
    //         i++; j++;
    //     }
    //     else
    //         break;
    // }
    // return ans;

    // M-2: Select the first string and compare with others:    Time: O(n*m), Space: O(s[0].size())
    string s1 = str[0];
    int ansLen = s1.length();
    // now compare s1 with other string and and change ansLen:
    for (int i = 1; i < str.size(); i++)
    {
        int j = 0;
        while(j<s1.size() && j<str[i].size() && s1[j]==str[i][j]){
            j++;
        }
        ansLen = min(ansLen, j);
    }
    string ansStr = s1.substr(0, ansLen);
    return ansStr;
    

}

// GFG Solution:    Time: O(n*m), Space: O(1)
// Function to find the longest common prefix using GFG approach
string longestCommonPrefixGFG(vector<string> arr) {
    if (arr.empty()) return ""; // If the vector is empty, return an empty string
    if (arr.size()==1) return arr[0]; // If there is only one string in the vector, return that string
    string ans=""; // Initialize the answer string
    for(int i=1; i<arr.size(); i++){ // Iterate through the vector starting from the second string as we select the first string as the reference
        int j=0; // Initialize the index for comparing characters
        while(j<arr[0].length() && j<arr[i].length()){ // Iterate through the characters of the strings
            if(arr[0][j]!=arr[i][j]) break; // If the characters are not equal, break the loop
            j++; // Increment the index
        }
        int len = ans.length()!=0? ans.length():arr[0].length();
        int ansLen = min(len, j); // Find the minimum of the current index and the length of the answer string
        ans = arr[0].substr(0, ansLen); // Update the answer string with the common prefix
        if (ans.empty()) break; // If the answer string is empty, break the loop
    }
    return ans==""? "-1" : ans; // Return the answer string or -1 if it is empty
}

int main(){
    int n;
    cin>>n;
    vector<string> str(n);  // Input: 3 geeksfor geek geeksforgeeks
    for (int i = 0; i < str.size(); i++){
        cin>>str[i];
    }
    
    // cout<<longestCommonPrefix(str);
    cout<<longestCommonPrefixGFG(str);
    
    return 0;
}

