#include<iostream>
#include<vector>
using namespace std;

class Queue{
    vector<int> arr;
    int f, r, cs, ms;
    public:
    Queue(int ds=5){
        arr.resize(ds);
        cs = 0;
        ms = ds;
        f = 0;
        r = ds-1;
    }
    bool full(){
        return cs==ms;
    }
    bool empty(){
        return cs==0;
    }
    void push(int data){
        if(!full()){
            r = (r+1)%ms;
            arr[r] = data;
            cs++;
        }
    }
    void pop(){
        if(!empty()){
            f = (f+1)%ms;
            cs--;
        }
    }
    int front(){
        return arr[f];
    }
    void print(){
        int count = 0;
        int i = f;
        while(count<cs){
            cout<<arr[i]<<" ";
            i = (i+1)%ms;
            count++;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    for(int i=1;i<=6;i++){
        q.push(i);
    }
    q.print();
    q.pop();
    q.print();
    q.push(8);
    q.push(9);
    q.print();
    return 0;
}