#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Count Sort in Strings:
string countSortInString(string &str){
    // Create frquency array:
    vector<int> freq(26, 0);

    // traverse the string and store the frequency of every char:
    for (int i = 0; i < str.length(); i++){
        int idx = str[i] - 'a';
        freq[idx]++;
    }

    int j = 0;
    // create our sorted string:
    for (int i = 0; i < 26; i++){
        while (freq[i]--){
            str[j] = i + 'a';
            j++;
        }
    }
    return str;
}

int main(){
    string str;
    cin>>str;

    cout<<countSortInString(str);
    
    return 0;
}