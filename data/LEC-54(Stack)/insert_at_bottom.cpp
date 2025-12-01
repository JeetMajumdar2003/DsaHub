#include<iostream>
#include<stack>
using namespace std;

// Insert element at Bottom:
// Iterative Solution:
void insertAtBottom(stack<int> &s,  int x){
    // Create a temporary stack:
    stack<int> temp;

    // Remove elements from original stack till Bottom:
    while (not s.empty()){
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }

    // Push element at Bottom:
    s.push(x);

    // Push back elements from temporary stack to original stack:
    while(not temp.empty()){
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}

// Recursive Solution:
void insertAtBottomRecursively(stack<int> &s, int x){
    // Base case:
    if(s.empty()){
        s.push(x);
        return;
    }

    // Hypothesis:
    int temp = s.top();
    s.pop();
    insertAtBottomRecursively(s, x);

    // Induction:
    s.push(temp);
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

    // Insert element at Bottom:
    insertAtBottom(s, 50);
    insertAtBottomRecursively(s, 60);

    // Print Stack:
    cout<<"After Inserting: "<<endl;
    print(s);
    cout<<endl;
    return 0;
}