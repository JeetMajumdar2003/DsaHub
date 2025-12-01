#include <iostream>
#include <set>
#include<string>
#include <algorithm>
using namespace std;


bool checkAllAlphabets(string s) {
    if(s.length() < 26) {
        return false;
    }
    transform(s.begin(), s.end(), s.begin(), ::tolower);    // convert string to lowercase
    set<char> st(s.begin(), s.end());
    return (st.size() == 26);
}

int main() {
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    if(checkAllAlphabets(s)) {
        cout<<"The string contains all the alphabets."<<endl;
    }
    else {
        cout<<"The string does not contain all the alphabets."<<endl;
    }
    return 0;
}