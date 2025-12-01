#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Print vector:
void print(vector<int> &v){
    for (int i = 0; i < v.size(); i++){
        if(v[i] != -1) cout<<i<<"->"<<v[i]<<endl;
    }
    cout<<endl;
}

// Count Sort in Strings:
bool isIsomorphic(string &s, string &t){
    // creating index array of size 128 and initialized with -1:
    vector<int> v1(26, -1); // v1 will store the index of each character in string s
    vector<int> v2(26, -1); // v2 will store the index of each character in string t

    // if length of both strings are not the same, then return false:
    if(s.length() != t.length()) return false;

    // traverse the s and t strings:
    for (int i = 0; i < s.length(); i++){
        // if the index of the current character in s is not equal to the index of the current character in t,
        // then the strings are not isomorphic, so return false:
        if (v1[s[i]-'a'] != v2[t[i]-'a']){
            return false;
        }
        // store the index of the current character in both v1 and v2:
        v1[s[i]-'a'] = v2[t[i]-'a'] = i;
    }

    // Print the index array:
    print(v1);
    print(v2);

    // if all characters are mapped correctly, return true:
    return true;
}

int main(){
    string s, t;
    cin>>s>>t;

    cout<<isIsomorphic(s, t);
    
    return 0;
}
