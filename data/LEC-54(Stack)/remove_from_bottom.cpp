#include<iostream>
#include<stack>
using namespace std;

// Remove element from Bottom:
// Iterative Solution:
void remove(stack<int> &s){
    // Create a temporary stack:
    stack<int> temp;

    // Remove elements from original stack till Bottom:
    while (s.size() != 1){
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }

    // Remove nth element:
    s.pop();

    // Push back elements from temporary stack to original stack:
    while(not temp.empty()){
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}

// Recursive Solution:
void removeRecursively(stack<int> &s){
    // Base case:
    if(s.size()==1){
        s.pop();
        return;
    }

    // Hypothesis:
    int temp = s.top();
    s.pop();
    removeRecursively(s);

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

    // Remove element from Bottom: 0-based indexing used(bottom-most element is at index 0):
    // remove(s);
    removeRecursively(s);

    // Print Stack:
    cout<<"After Removing: "<<endl;
    print(s);
    cout<<endl;
    return 0;
}