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
};

int main(){
    Node* new_node = new Node(3);

    DoublyLinkedList dll;
    dll.head = new_node;
    dll.tail = new_node;
    cout << dll.head->data << endl;
    return 0;

}