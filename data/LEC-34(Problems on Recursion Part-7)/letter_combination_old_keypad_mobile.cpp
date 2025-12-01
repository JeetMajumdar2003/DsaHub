#include <bits/stdc++.h>
using namespace std;

void f(string &str, int i, string result, vector<string> &li, vector<string> &v){
    // base case
    if(i == str.size()){
        li.push_back(result);
        return;
    }
    // extract the digit
    int digit = str[i]-'0';
    // if digit = 0 or 1, then just call next function and return
    if(digit<=1){
        f(str, i+1, result, li, v);
        return;
    }
    // else, call for all the characters of that digit: here
    for (int j = 0; j < v[digit].size(); j++){
        f(str, i+1, result + v[digit][j], li, v);
    }
    return;
}

int main()
{
    // define the keypad using vector of strings
    vector<string> v(10); 
    v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    //    0   1    2      3      4      5      6      7       8      9

    vector<string> li;
    string str = "23", result;
    f(str, 0, result, li, v);

    // print the list:
    for(int i=0; i<li.size(); i++){
        cout<<li[i]<<" ";
    }
    return 0;
}