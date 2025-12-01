#include<iostream>
#include<stack>
#include<string>
#include<cmath>
using namespace std;

// Calculator Operations:
int calc(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        case '^': return pow(a, b);
    }
    return 0;
}

// Prefix to Postfix conversion:
string prefixToPostfix(string &str) {
    stack<string> s;
    for(int i = str.length() - 1; i >= 0; i--) { // and also we can reverse the string and traverse from left to right
        char ch = str[i];
        if(isalnum(ch)) {
            s.push(string(1, ch));
        } else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + ch;
            s.push(temp);
        }
    }
    return s.top();
}

int main() {
    string exp = "*-A/BC-/AKL";
    cout << "Postfix evaluation of given prefix expression: " << exp <<" is: "<< prefixToPostfix(exp) << endl;
    return 0;
}