#include<iostream>
#include<stack>
using namespace std;

// Remove element from nth index:
// Iterative Solution:
void remove(stack<int> &s, int n){
    // Create a temporary stack:
    stack<int> temp;
    // Size of original stack:
    int size = s.size();

    // Remove elements from original stack till nth index:
    for(int i=0; i<size-n-1; i++){
        temp.push(s.top());
        s.pop();
    }

    // Remove nth element:
    s.pop();

    // Push back elements from temporary stack to original stack:
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}

// Recursive Solution:
void removeRecursively(stack<int> &s, int n){
    // Base case:
    if(s.size()==n+1){
        s.pop();
        return;
    }

    // Hypothesis:
    int temp = s.top();
    s.pop();
    removeRecursively(s, n);

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

    // Remove element from nth index: 0-based indexing used(bottom-most element is at index 0):
    // remove(s, 1);
    removeRecursively(s, 2);

    // Print Stack:
    cout<<"After Removing: "<<endl;
    print(s);
    cout<<endl;
    return 0;
}