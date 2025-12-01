#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);
    for(auto x: dq){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    dq.pop_back();
    dq.pop_front();
    for(auto x: dq){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<dq.size()<<endl;
    cout<<dq.empty()<<endl;
    return 0;
}

/**
 * Deque is a double ended queue
 * It is a sequence container
 * It is similar to vector but more efficient in case of insertion and deletion
 * It is a dynamic array
 * 
*/