#include<iostream>
#include<stack>
using namespace std;

// Copy Stack:
// Iterative Solution:
stack<int> copy(stack<int> &s){
    // Create a temporary stack:
    stack<int> temp;
    // Remove elements from original stack till Bottom:
    while (not s.empty()){
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }

    // result stack:
    stack<int> result;

    // Push back elements from temporary stack to result stack:
    while(not temp.empty()){
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

// Recursive Solution:
stack<int> copyRecursively(stack<int> &s, stack<int> &result){
    // Base case:
    if(s.empty()){
        return result;
    }

    // Hypothesis:
    int curr = s.top();
    s.pop();
    copyRecursively(s, result);

    // Induction:
    s.push(curr);
    result.push(curr);
    return result;
}

// Print Stack:
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }
}

int main(){
    // Create Stack:
    stack<int> s;

    // Push elements:
    s.push(10); // idx: 0
    s.push(20); // idx: 1
    s.push(30); // idx: 2
    s.push(40); // idx: 3
    print(s);   // 40 30 20 10

    // result stack:
    stack<int> result;


    // Copy Stack: Iterative Solution:
    result = copy(s);

    // Recursive Solution:
    // copyRecursively(s, result);

    cout<<"After Copying:\n";
    print(result);   // 40 30 20 10

    return 0;
}