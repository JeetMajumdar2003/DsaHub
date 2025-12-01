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

// Precedence of operators:
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return -1;
}

// Infix Expression evaluation:
int infixEval(string &str){
    stack<int> s;
    stack<char> op;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if(ch == ' ') continue;
        if(isdigit(ch)) {
            int num = 0;
            while(i < str.length() && isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--;
            s.push(num);
        } else if(ch == '(') {
            op.push(ch);
        } else if(ch == ')') {
            while(!op.empty() && op.top() != '(') {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                char opr = op.top();
                op.pop();
                s.push(calc(a, b, opr));
            }
            if(!op.empty()) op.pop();
        } else {
            while(!op.empty() && precedence(op.top()) >= precedence(ch)) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                char opr = op.top();
                op.pop();
                s.push(calc(a, b, opr));
            }
            op.push(ch);
        }
    }
    while(!op.empty()) {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        char opr = op.top();
        op.pop();
        s.push(calc(a, b, opr));
    }
    return s.top();

}

int main() {
    string exp = "1 * (2 - 3) - 9";
    cout << "Infix evaluation: " << exp <<" is: "<< infixEval(exp) << endl;
    return 0;
}