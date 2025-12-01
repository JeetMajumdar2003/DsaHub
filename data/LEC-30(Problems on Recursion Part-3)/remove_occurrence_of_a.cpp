#include <iostream>
#include<string>
using namespace std;

string removeOcc(string &str, int idx, int n){

    // Base Case
    if(idx == n) return "";
    // self work and assumption:
    // if(str[idx]!='a'){
    //     return str[idx] + removeOcc(str, idx+1, n);
    // }
    // return removeOcc(str, idx+1, n);

    // Using Ternary Operator:
    string curr = "";
    curr += str[idx];
    return ((str[idx]=='a') ? "" : curr) + removeOcc(str, idx+1, n);
}

int main()
{
    string s = "abcax";
    string result = removeOcc(s, 0, 5);
    cout<<result;
    return 0;
}