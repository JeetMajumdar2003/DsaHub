#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Count Sort in Strings:
bool anagramString(string &s, string &t){
    // Create frquency array:
    vector<int> freq(26, 0);

    if(s.length() != t.length()) return false;

    // traverse the string and store the frequency of every char:
    for (int i = 0; i < s.length(); i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }

    // create our sorted string:
    for (int i = 0; i < 26; i++){
        if(freq[i]!=0) return false;
    }
    return true;
}

int main(){
    string s, t;
    cin>>s>>t;

    cout<<anagramString(s, t);
    
    return 0;
}