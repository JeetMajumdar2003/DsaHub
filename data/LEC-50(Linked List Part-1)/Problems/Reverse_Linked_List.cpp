#include <iostream>
using namespace std;

// Linked List Node class
class Node {
    public:
        int val;
        Node* next;

        // Node Constructor
        Node(int data) {
            val = data;
            next = NULL;
        }
};

// Linked List class:
class LinkedList {
    public:
        Node* head; // Head Node of the Linked List
        Node* tail; // Tail Node of the Linked List

        // Linked List Constructor
        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        // Insert a node at the end of the Linked List
        void insert(int data) {
            // Create a new node
            Node* new_node = new Node(data);

            // If the Linked List is empty
            if (head == NULL) {
                head = new_node;
                tail = new_node;
            }
            // If the Linked List is not empty
            else {
                tail->next = new_node;
                tail = new_node;
            }
        }

        // Print the Linked List
        void print() {
            Node* temp = head;
            while (temp != NULL) {
                cout<<temp->val<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

// Reverse a Linked List
Node* reverseLinkedList(Node* &head) {
    // Store the current, previous and next nodes:
    Node* currNode = head;
    Node* prevNode = NULL;

    // Iterate over the Linked List:
    while (currNode != NULL) {
        // Store the next node:
        Node* nextNode = currNode->next;

        // Reverse the current node:
        currNode->next = prevNode;

        // Update the previous node:
        prevNode = currNode;

        // Update the current node:
        currNode = nextNode;

    }

    // When the Loop ends, the prevNode will be pointing to the last node of the Linked List which will be the new head of the Linked List:
    Node* newHead = prevNode;

    // Return the new head of the Linked List:
    return newHead;
}

// Reverse a Linked List using Recursion:
Node* reverseLinkedListRecursion(Node* &head) {
    // Base Case:
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursive Case:
    Node* newHead = reverseLinkedListRecursion(head->next);

    // Reverse the current node:
    head->next->next = head;
    head->next = NULL;

    // Return the new head of the Linked List:
    return newHead;
}

int main() {
    // Create a Linked List
    LinkedList ll;

    // Insert elements into the Linked List
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);

    // Print the Linked List
    ll.print();

    // Reverse the Linked List
    // ll.head = reverseLinkedList(ll.head);

    // Reverse the Linked List using Recursion
    ll.head = reverseLinkedListRecursion(ll.head);

    // Print the Linked List
    ll.print();

    return 0;
}
