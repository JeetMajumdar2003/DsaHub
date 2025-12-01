#include<iostream>
#include<stack>
using namespace std;

// Implement queue using stack pop efficient
class Queue{
    stack<int> st;
    public:
    Queue(){}
    void push(int x){
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    void pop(){
        if(st.empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        st.pop();
    }
    bool empty(){
        return st.empty();
    }
    int front(){
        if (st.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return st.top();
    }
    int size(){
        return st.size();
    }
    void print(){
        stack<int> temp = st;
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.print();
    cout<<q.front()<<endl;
    q.pop();
    q.print();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}