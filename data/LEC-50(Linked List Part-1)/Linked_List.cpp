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

int main() {
    // Create a Linked List
    Node* head = new Node(1);
    cout<<head->val<<" "<<head->next<<endl; // 1 0x0

    // Create a Linked List
    LinkedList* l = new LinkedList();
    for (int i = 1; i <= 5; i++) {
        l->insert(i);
    }
    l->print(); // 1->2->3->4->5->NULL

    return 0;
}
