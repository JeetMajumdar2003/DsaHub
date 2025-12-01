#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Linked list class
class LinkedList {
    
public:
// private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    public:
    Node* getHead() const {
        return head;
    }

    // Insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display the elements of the list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<< "NULL" << endl;
    }
};

// Swap Adjacent Nodes:(Recursive)
// Given a linked list, swap every two adjacent nodes and return its head.  
// 1->2->3->4->5->6->NULL
// 2->1->4->3->6->5->NULL
Node* swapAdjacentNodes(Node* &head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // Recursive case
    Node* secondNode = head->next;
    head->next = swapAdjacentNodes(head->next->next);
    secondNode->next = head; // Reversing the links of the adjacent nodes
    return secondNode;
}

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.display();

    // Swap Adjacent Nodes:(Recursive)
    Node* newHead = swapAdjacentNodes(list.head);
    list.head = newHead;
    list.display();
    return 0;
}