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

// Reverse a Linked List using Recursion:
Node* reverseKllRecursion(Node* &head, int k) {
    // Create Pointers
    Node* prevNode = NULL;
    Node* currNode = head;

    int counter = 0; // for counting first k nodes

    // Reverse the first k nodes
    while (currNode != NULL && counter < k) {
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        counter++;
    }
    // prevNode is now pointing to the head of the reversed Linked List
    // If there are more nodes left in the Linked List
    // currNode is now pointing to (k+1)th node
    if (currNode != NULL) {
        Node* newHead = reverseKllRecursion(currNode, k);   // Recursively reverse the remaining nodes
        head->next = newHead;
    }

    // Return the new head of the reversed Linked List
    return prevNode; // prevNode is the new head of the connected Linked List


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
    ll.insert(6);

    // Print the Linked List
    ll.print();

    // Reverse the Linked List in groups of k
    int k = 2;

    // Reverse the Linked List using Recursion
    ll.head = reverseKllRecursion(ll.head, k);

    // Print the Linked List
    ll.print();

    return 0;
}
