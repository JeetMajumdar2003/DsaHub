#include<iostream>
#include<stack>
using namespace std;

// Given a string s of '(', '{', '[', ']', '}', ')', we have to delete minimum number of brackets to make the string valid.
// A string is valid if it has equal number of opening and closing brackets and the brackets are in correct order.
// Function to find the minimum number of brackets to delete to make the string valid.
// Approach: We can use stack to solve this problem. We will iterate through the string and if we find an opening bracket, we will push it into the stack.
// If we find a closing bracket, we will check if the stack is empty or the top of the stack is not the corresponding opening bracket. If it is, we will push the closing bracket into the stack.
// If the top of the stack is the corresponding opening bracket, we will pop the top of the stack.
// In the end, the stack will contain the brackets which are not in correct order. The size of the stack will be the minimum number of brackets to delete to make the string valid.
int minBrackets(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.empty() || (s[i] == ')' && st.top() != '(') || (s[i] == '}' && st.top() != '{') || (s[i] == ']' && st.top() != '[')) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
    }
    // at the end, the stack will contain the brackets which are not in correct order.
    return st.size();
}

// M-2 My method
int minBrackets2(string s) {
    stack<char> st;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if((s[i] == ')' && st.top() != '(') || (s[i] == '}' && st.top() != '{') || (s[i] == ']' && st.top() != '[')) {
                cnt++;
                st.pop();
            } else if (st.empty()) {
                cnt++;
            } else {
                st.pop();
            }
                
        }
    }
    // at the end, the stack will contain the brackets which are not in correct order.
    return cnt;
}

// M-3: Best method
int minBrackets3(string s) {
    stack<char> st;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.empty() || (s[i] == ')' && st.top() != '(') || (s[i] == '}' && st.top() != '{') || (s[i] == ']' && st.top() != '[')) {
                cnt++;
            } else {
                st.pop();
            }
        }
    }
    // at the end, the stack will contain the brackets which are not in correct order. The size of the stack will be the minimum number of brackets to delete to make the string valid. 
    return cnt + st.size();
}

int main() {
    string s;
    cin >> s;
    stack<char> st;
    
    cout << minBrackets(s) << endl;
    cout << minBrackets2(s) << endl;
    cout << minBrackets3(s) << endl;
    return 0;
}

// Given a string s of '(', '{', '[', ']', '}', ')', we have to delete minimum number of brackets to make the string valid.
// A string is valid if it has equal number of opening and closing brackets and the brackets are in correct order.
// Function to find the minimum number of brackets to delete to make the string valid.
// Approach: We can use stack to solve this problem. We will iterate through the string and if we find an opening bracket, we will push it into the stack.
// If we find a closing bracket, we will check if the stack is empty or the top of the stack is not the corresponding opening bracket. If it is, we will increment the count of brackets to delete.
// If the top of the stack is the corresponding opening bracket, we will pop the top of the stack.
// In the end, the stack will contain the brackets which are not in correct order. The size of the stack will be the minimum number of brackets to delete to make the string valid.
// Time complexity: O(n), where n is the length of the string s.
// Space complexity: O(n), where n is the length of the string s. The stack will contain at most n elements.
// int minBrackets(string s) {
//     stack<char> st;
//     int cnt = 0;
//     for(int i = 0; i < s.length(); i++) {
//         if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
//             st.push(s[i]);
//         } else {
//             if(st.empty() || (s[i] == ')' && st.top() != '(') || (s[i] == '}' && st.top() != '{') || (s[i] == ']' && st.top() != '[')) {
//                 cnt++;
//             } else {
//                 st.pop();
//             }
//         }
//     }
//     // at the end, the stack will contain the brackets which are not in correct order. The size of the stack will be the minimum number of brackets to delete to make the string valid. 
//     return cnt + st.size();
// }