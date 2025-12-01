#include<iostream>
#include<stack>
using namespace std;

// Insert element at any index:
// Iterative Solution:
void insert(stack<int> &s, int x, int idx){
    // Create a temporary stack:
    stack<int> temp;

    // Remove elements from original stack till idx:
    while (idx--){
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }

    // Push element at idx:
    s.push(x);

    // Push back elements from temporary stack to original stack:
    while(not temp.empty()){
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}

// Recursive Solution:
void insertRecursively(stack<int> &s, int x, int idx){
    // Base case:
    if(s.size()==idx){
        s.push(x);
        return;
    }

    // Hypothesis:
    int temp = s.top();
    s.pop();
    insertRecursively(s, x, idx);

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
    insert(s, 50, 2);
    insertRecursively(s, 60, 2);

    // Print Stack:
    cout<<"After Inserting: "<<endl;
    print(s);
    cout<<endl;
    return 0;
}