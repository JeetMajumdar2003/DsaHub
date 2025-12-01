#include<iostream>
using namespace std;

// Stack Class:
class Stack{
    private:
        int capacity;
        int* arr;
        int topIdx;
    
    public:
        // Stack Constructor:
        Stack(int capacity){
            this->capacity = capacity;
            this->arr = new int[capacity];
            this->topIdx = -1;
        }

        // Push Function:
        void push(int data){
            // Check if Stack is full:
            if(topIdx == capacity-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            // Increment topIdx and add data:
            topIdx++;
            arr[topIdx] = data;
        }

        // Pop Function:
        void pop(){
            // Check if Stack is empty:
            if(topIdx == -1){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            // Decrement topIdx:
            topIdx--;
        }

        // getTop Function:
        int getTop(){
            // Check if Stack is empty:
            if(topIdx == -1){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            // Return top element:
            return arr[topIdx];
        }

        // isEmpty Function:
        bool isEmpty(){
            return topIdx == -1;
        }

        // getSize Function:
        int getSize(){
            return topIdx+1;
        }

        // isFull Function:
        bool isFull(){
            return topIdx == capacity-1;
        }

        // Print Function:
        void print(){
            // Check if Stack is empty:
            if(topIdx == -1){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            // Print Stack:
            for(int i=0; i<=topIdx; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        // Destructor:
        ~Stack(){
            cout<<"Destructor Called"<<endl;
            delete[] arr;
        }

};

// Main Function:
int main(){
    // Create Stack:
    Stack s(5);

    // Push Elements:
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // Print Stack:
    s.print();

    // Pop Elements:
    s.pop();
    s.pop();

    // Print Stack:
    s.print();

    // Get Top Element:
    cout<<s.getTop()<<endl;

    // Check if Stack is Empty:
    cout<<s.isEmpty()<<endl;

    // Check if Stack is Full:
    cout<<s.isFull()<<endl;

    // Get Size of Stack:
    cout<<s.getSize()<<endl;

    // Destructor will be called automatically:


    return 0;
}