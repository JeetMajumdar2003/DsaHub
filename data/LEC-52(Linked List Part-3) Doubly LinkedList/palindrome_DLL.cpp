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

// Check Palindrome:
bool isPalindromeDLL(Node* head, Node* tail){
    Node* start = head;
    Node* end = tail;
    while(start != end && end != start->prev){
        if(start->data != end->data){
            return false;
        }
        start = start->next;
        end = end->prev;
    }
    return true;
}

int main() {
    DoublyLinkedList dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(3);
    dll.insert(2);
    dll.insert(1);
    dll.display();
    cout << isPalindromeDLL(dll.head, dll.tail) << endl;
    return 0;
}