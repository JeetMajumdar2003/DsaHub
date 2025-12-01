#include<iostream>
using namespace std;

// Node class
class Node {    
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
    public:
        Node* head;
        Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insertion at the end of the list
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Display the list
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }cout<<endl;
    }
};

// Reverse the doubly linked list: Naive approach
void reverse(Node* &head, Node* &tail){
    Node* currPtr = head;
    Node* nextPtr = NULL;
    while (currPtr != NULL){
        nextPtr = currPtr->next;
        currPtr->next = currPtr->prev;
        currPtr->prev = nextPtr;
        currPtr = nextPtr;
    }
    // Swap head and tail:
    Node* newHead = tail;
    tail = head;
    head = newHead;
    return;
}

int main(){
    // Creating a doubly linked list
    DoublyLinkedList dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);
    dll.insert(5);
    dll.display();

    // Reversing the doubly linked list
    reverse(dll.head, dll.tail);
    dll.display();
    return 0;

}