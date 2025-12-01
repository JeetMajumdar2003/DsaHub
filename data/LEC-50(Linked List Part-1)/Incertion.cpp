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

// Insertion at the beginning of the Linked List
void insertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Insertion at the end of the Linked List
void insertAtEnd(Node* &head, int data) {
    Node* newNode = new Node(data);
    // Check if the Linked List is empty
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // temp is reached to the last node
    temp->next = newNode;
}

// Insertion at the given position of the Linked List
void insertAtPosition(Node* &head, int data, int pos) {
    Node* newNode = new Node(data);
    // Check if the Linked List is empty
    if(head == NULL) {
        head = newNode;
        return;
    }
    // Check if the position is 0
    if(pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    int currentPos = 0;
    while(currentPos != pos-1) {
        temp = temp->next;
        currentPos++;
    }
    // temp is reached to the node just before the position
    newNode->next = temp->next;
    temp->next = newNode;
}


// Print the Linked List:
void display(Node* head) {
    // Traversal: create a temp pointer to head, and check if it is NULL
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    // Create a Linked List
    Node* head = NULL; // Empty Linked List

    // Insertion at the Beginning:
    // insertAtBeginning(head, 1);
    // display(head); // 1 NULL
    // insertAtBeginning(head, 2);
    // display(head); // 2 1 NULL
    // insertAtBeginning(head, 3);
    // display(head); // 3 2 1 NULL

    // Insertion at the End:
    // insertAtEnd(head, 1);
    // display(head); // 1 NULL
    // insertAtEnd(head, 2);
    // display(head); // 1 2 NULL
    // insertAtEnd(head, 3);
    // display(head); // 1 2 3 NULL

    // Insertion at the given position:
    // insertAtPosition(head, 1, 0);
    // display(head); // 1 NULL
    // insertAtPosition(head, 2, 1);
    // display(head); // 1 2 NULL
    // insertAtPosition(head, 3, 1);
    // display(head); // 1 3 2 NULL
    // insertAtPosition(head, 4, 2);
    // display(head); // 1 4 3 2 NULL

    return 0;
}
