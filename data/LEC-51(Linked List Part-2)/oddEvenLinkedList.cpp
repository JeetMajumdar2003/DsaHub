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

// Odd even linked list:
// Given a singly linked list, group all odd nodes together followed by the even nodes.
Node* oddEvenList(Node* &head) {
    if (head == NULL) {
        return NULL;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while (even != NULL && even->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
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

    // Odd even linked list
    oddEvenList(list.head);
    list.display();

    return 0;
}