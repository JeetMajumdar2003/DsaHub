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

// Delete duplicate nodes of a Linked List:
void deleteDuplicateNodes(LinkedList* l) {
    // If the Linked List is empty
    if (l->head == NULL) {
        return;
    }
    // Create a temporary pointer to traverse the Linked List
    Node* currentNode = l->head;
    // Traverse the Linked List

    // Method 1: Using a temporary pointer
    while (currentNode != NULL) {
        // If the current node and the next node have the same value
        while (currentNode->next != NULL && currentNode->val == currentNode->next->val) {
            // Delete the next node(currentNode->next)
            Node* temp = currentNode->next;
            currentNode->next = currentNode->next->next;
            delete temp;
        }
        // If the current node and the next node have different values than Move to the next node
        currentNode = currentNode->next;
    } 

    // Method 2: Using a temporary pointer
    // while (currentNode->next != NULL) {
    //     // If the current node and the next node have the same value
    //     while (currentNode->next != NULL && currentNode->val == currentNode->next->val) {
    //         // Delete the next node(currentNode->next)
    //         Node* temp = currentNode->next;
    //         currentNode->next = currentNode->next->next;
    //         delete temp;
    //     }
    //     // If the current node and the next node have different values
    //     if (currentNode->next != NULL) {
    //         // Move to the next node
    //         currentNode = currentNode->next;
    //     }
    // } 

    // Method 3: Without using a temporary pointer
    // while (currentNode != NULL && currentNode->next != NULL) {
    //     // If the current node and the next node have the same value
    //     if (currentNode->val == currentNode->next->val) {
    //         // Delete the next node
    //         Node* temp = currentNode->next;
    //         currentNode->next = currentNode->next->next;
    //         delete temp;
    //     }
    //     // If the current node and the next node have different values
    //     else {
    //         // Move to the next node
    //         currentNode = currentNode->next;
    //     }
    // }
}


int main() {
    // Create a Sorted Linked List
    LinkedList* l = new LinkedList(); // Empty Linked List
    // Insert elements into the Linked List
    l->insert(1);
    l->insert(2);
    l->insert(2);
    l->insert(3);
    l->insert(3);
    l->insert(3);
    // Print the Linked List
    l->print(); // 1->2->2->3->3->3->NULL

    // Delete duplicate nodes of the Linked List:
    deleteDuplicateNodes(l);
    // Print the Linked List
    l->print(); // 1->2->3->NULL


    return 0;
}
