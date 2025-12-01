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

// Delete same Neighbour nodes in a Doubly Linked List:
void deleteSameNeighbourNodes(Node* &head, Node* &tail){
    Node* currPtr = tail->prev;
    while(currPtr != head){
        Node* prevPtr = currPtr->prev;
        Node* nextPtr = currPtr->next;
        if(prevPtr->data == nextPtr->data){
            prevPtr->next = nextPtr;
            nextPtr->prev = prevPtr;
            free(currPtr);
        }
        currPtr = prevPtr;
    }
    return;
}

int main(){
    DoublyLinkedList dll;
    dll.insert(2);
    dll.insert(1);
    dll.insert(1);
    dll.insert(2);
    dll.insert(1);

    cout << "Original Doubly Linked List: ";
    dll.display();

    deleteSameNeighbourNodes(dll.head, dll.tail);

    cout << "Doubly Linked List after deleting same neighbour nodes: ";
    dll.display();

    return 0;
}