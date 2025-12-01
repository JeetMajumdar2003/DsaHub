#include<iostream>
#include <string.h> // also #include <string> 
#include<algorithm>
using namespace std;

int main(){
    string str = "abcdefghij";

    // (1) reverse():
    // reverse(str.begin(), str.end());
    // cout<<str;

    // (2) substr():
    // cout<<str.substr(0,5);
    // cout<<str.substr(0);

    // (3) The '+' Operator:
    // string s1 = "Jeet";
    // string s2 = "Majumdar";
    // string s3 = s1 + " " + s2;
    // cout<<s3;

    // (4) strcat():
    // char s1[20] = "college";
    // strcat(s1, "wallah");
    // cout<<s1; 

    // (5) push_back():
    // string s1 = "abcd";
    // s1.push_back('e');
    // cout<<s1;

    // (6) size() or length():
    // cout<<str.size()<<"\n";
    // cout<<str.length();

    // (7) strlen():
    // char s[20] = "abcde";
    // cout<<strlen(s);

    // (8) to_string():
    // int num = 45;
    // string numStr = to_string(num);
    // numStr += '1';
    // cout<<numStr;

    return 0;
}