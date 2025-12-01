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

// Print the Linked List in reverse order:
void reversePrint(Node* head) {
    // If the Linked List is empty (Base Case)
    if (head == NULL) {
        return;
    }

    // Print the Linked List in reverse order (Recursive Case)
    reversePrint(head->next);
    cout<<head->val<<" ";

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

    // Print the Linked List in reverse order
    reversePrint(ll.head);

    return 0;
}
