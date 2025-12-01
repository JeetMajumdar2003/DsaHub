#include<iostream>
#include<stack>
#include<string>
#include<cmath>
using namespace std;

// Calculator Operations:
// 1. Addition
// 2. Subtraction
// 3. Multiplication
// 4. Division
// 5. Modulus
// 6. Exponentiation
// 7. Parentheses
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

// Postfix expression evaluation:
int postfixEval(string exp) {
    stack<int> s;
    for(int i = 0; i < exp.length(); i++) {
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
    string exp = "231*+9-";
    cout << "Postfix evaluation: " << exp <<" is: "<< postfixEval(exp) << endl;
    return 0;
}