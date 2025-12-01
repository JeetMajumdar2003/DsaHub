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

// Prefix expression evaluation:
int prefixEval(string exp) {
    stack<int> s;
    for(int i = exp.length()-1; i >= 0; i--) {
        char ch = exp[i];
        if(isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            s.push(calc(a, b, ch));
        }
    }
    return s.top();
}

int main() {
    string exp = "-9+*132";
    cout << "Prefix evaluation: " << exp <<" is: "<< prefixEval(exp) << endl;
    return 0;
}