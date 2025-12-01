#include<iostream>
using namespace std;

// Node Class:
class Node{
    public:
        int data;
        Node* next;

        // Node Constructor:
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// Stack Class:
class Stack{
    private:
        Node* head;
        int capacity;
        int currSize;

    public:
        // Stack Constructor:
        Stack(int capacity){
            this->capacity = capacity;
            this->head = NULL;
            this->currSize = 0;
        }

        // Push Function:
        void push(int data){
            // Check if Stack is full:
            if(currSize == capacity){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            // Create new Node:
            Node* newNode = new Node(data);
            // Add new Node to Stack:
            newNode->next = head;
            head = newNode;
            // Increment currSize:
            currSize++;
        }

        // Pop Function:
        void pop(){
            // Check if Stack is empty:
            if(currSize == 0){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            // Remove top Node:
            Node* temp = head;
            head = head->next;
            delete temp;
            // Decrement currSize:
            currSize--;
        }

        // getTop Function:
        int getTop(){
            // Check if Stack is empty:
            if(currSize == 0){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            // Return top element:
            return head->data;
        }

        // isEmpty Function:
        bool isEmpty(){
            return currSize == 0; //OR head == NULL;
        }

        // getSize Function:
        int getSize(){
            return currSize;
        }

        // isFull Function:
        bool isFull(){
            return currSize == capacity;
        }

        // Print Function:
        void print(){
            // Check if Stack is empty:
            if(currSize == 0){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            // Print Stack:
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        // Destructor:
        ~Stack(){
            cout<<"Destructor Called"<<endl;
            Node* temp = head;
            while(temp != NULL){
                Node* toBeDeleted = temp;
                temp = temp->next;
                delete toBeDeleted;
            }
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

    // Push Element:
    s.push(6);

    // Pop Elements:
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    // Print Stack:
    s.print();

    // Push Elements:
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // Print Stack:
    s.print();

    // Get Top Element:
    cout<<s.getTop()<<endl;

    // Get Size:
    cout<<s.getSize()<<endl;

    // Check if Stack is empty:
    cout<<s.isEmpty()<<endl;

    // Check if Stack is full:
    cout<<s.isFull()<<endl;

    // Destructor is called automatically:
    return 0;
}