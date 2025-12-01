#include <bits/stdc++.h>
using namespace std;

void subString(string &str, int i, string result, vector<string> &li){
    if(i==str.length()){
        li.push_back(result);
        return;
    }
    
    // pick i'th character
    subString(str, i+1, result+str[i], li);
    // don't pick i'th character
    subString(str, i+1, result, li);
}

int main()
{
    string str = "abc", result;
    vector<string> list;
    subString(str, 0, result, list);
    // print the list:
    for(int i=0; i<list.size(); i++){
        cout<<list[i]<<" ";
    }
    return 0;
}




// direc print
// void subString(string str, int i, int n, string result){
//     if(i==n){
//         cout<<result<<" ";
//         return;
//     }   
//     // pick i'th character
//     subString(str, i+1, n, result+str[i]);
//     // don't pick i'th character
//     subString(str, i+1, n, result);
// }
// int main()
// {
//     string str = "abc", result;
//     subString(str, 0, str.length(), result);
//     return 0;
// }