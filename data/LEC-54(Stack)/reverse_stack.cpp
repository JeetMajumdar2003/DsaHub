#include<iostream>
#include<stack>
using namespace std;

// Reverse Stack:
// Iterative Solution:
void reverse(stack<int> &s){
    // Create a two temporary stacks:
    stack<int> temp1, temp2;
    
    // Push elements from original stack to temp1:
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        temp1.push(curr);
    }
    // Push elements from temp1 to temp2:
    while(!temp1.empty()){
        int curr = temp1.top();
        temp1.pop();
        temp2.push(curr);
    }
    // Push elements from temp2 to original stack:
    while(!temp2.empty()){
        int curr = temp2.top();
        temp2.pop();
        s.push(curr);
    }
    return;
}

// Recursive Solution:
void insertAtBottom(stack<int> &s, int x){
    // Base case:
    if(s.empty()){
        s.push(x);
        return;
    }

    // Hypothesis:
    int temp = s.top();
    s.pop();
    insertAtBottom(s, x);

    // Induction:
    s.push(temp);
}
void reverseRecursively(stack<int> &s){
    // Base case:
    if(s.empty()){
        return;
    }

    // Hypothesis:
    int temp = s.top();
    s.pop();
    reverseRecursively(s);

    // Induction:
    insertAtBottom(s, temp);
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

    // Reverse Stack:
    // reverse(s);

    // Reverse Stack Recursively:
    reverseRecursively(s);

    cout<<"After reversing: \n";
    print(s);   // 40 30 20 10
    return 0;
}