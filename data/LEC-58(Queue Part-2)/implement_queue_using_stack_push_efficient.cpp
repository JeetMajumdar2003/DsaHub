#include<iostream>
#include<stack>
using namespace std;

// Implement queue using stack push efficient
class Queue{
    stack<int> st;
    public:
    Queue(){}
    void push(int x){
        st.push(x);
    }
    void pop(){
        if(st.empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        stack<int> temp;
        while(st.size()>1){
            temp.push(st.top());
            st.pop();
        }
        st.pop();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    bool empty(){
        return st.empty();
    }
    int front(){
        stack<int> temp;
        while(st.size()>1){
            temp.push(st.top());
            st.pop();
        }
        int x = st.top();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return x;
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