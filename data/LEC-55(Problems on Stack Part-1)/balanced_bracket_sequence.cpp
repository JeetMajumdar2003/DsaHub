#include<iostream>
#include<stack>
using namespace std;

// Function to check if the given string is balanced bracket sequence or not
bool isBalanced(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if (st.empty()){
                return 0;
            }
            else if(st.top()=='(' && s[i]==')'){
                st.pop();
            }
            else if(st.top()=='{' && s[i]=='}'){
                st.pop();
            }
            else if(st.top()=='[' && s[i]==']'){
                st.pop();
            }
        }
    }
    if (st.size()==0)
    {
        return 1;
    }
    return 0;
}

int main() {
    string s;
    cin >> s;
    if(isBalanced(s)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}

/**
 * M-2
 *  stack<char> st;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.empty()) {
                return false;
            }
            if(s[i] == ')' && st.top() != '(') {
                return false;
            }
            if(s[i] == '}' && st.top() != '{') {
                return false;
            }
            if(s[i] == ']' && st.top() != '[') {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
*/