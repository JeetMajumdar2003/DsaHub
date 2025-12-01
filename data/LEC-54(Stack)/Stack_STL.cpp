#include<iostream>
#include<stack>
using namespace std;

int main(){
    // Create Stack:
    stack<int> s;

    // Push elements:
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // Pop element:
    s.pop();

    // Get top element:
    cout<<"Top: "<<s.top()<<endl;

    // Get size:
    cout<<"Size: "<<s.size()<<endl;

    // Check if empty:
    cout<<"Empty: "<<s.empty()<<endl;

    // Print Stack:
    cout<<"Stack: ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}