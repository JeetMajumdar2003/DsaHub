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

// Delete alternate nodes of a Linked List
void deleteAlternateNodes(LinkedList* l) {
    // If the Linked List is empty
    if (l->head == NULL) {
        return;
    }
    // If the Linked List has only one node
    if (l->head->next == NULL) {
        return;
    }

    // If the Linked List has more than one node
    Node* currentNode = l->head;
    while (currentNode != NULL && currentNode->next != NULL) {
        Node* temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        delete temp;
        currentNode = currentNode->next;
    }
} 


int main() {
    // Create a Linked List
    LinkedList* l = new LinkedList(); // Empty Linked List
    // Insert elements into the Linked List
    l->insert(1);
    l->insert(2);
    l->insert(3);
    l->insert(4);
    l->insert(5);
    l->insert(6);
    // Print the Linked List
    l->print(); // 1->2->3->4->5->6->NULL

    // Delete alternate nodes of the Linked List
    deleteAlternateNodes(l);
    // Print the Linked List
    l->print(); // 1->3->5->NULL

    return 0;
}
