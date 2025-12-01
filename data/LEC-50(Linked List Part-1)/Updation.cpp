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

// Update at a given position:
void update(Node* head, int pos, int val) {
    Node* temp = head;
    int count = 0;
    while(count != pos) {
        temp = temp->next;
        count++;
    }
    // temp is reached to the node at the given position
    temp->val = val;
}

int main() {
    // Create a Linked List
    Node* head = new Node(1);

    // Insertion at the beginning
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 5);
    
    // Update at a given position
    update(head, 3, 12);
    
    // Print the Linked List
    display(head);
    return 0;
}
