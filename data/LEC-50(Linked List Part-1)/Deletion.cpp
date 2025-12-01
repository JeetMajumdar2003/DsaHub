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


// Deletion at the beginning of the Linked List
void deleteAtBeginning(Node* &head) {
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
}

// Deletion at the end of the Linked List:
void deleteAtEnd(Node* &head) {
    Node* secondLastNode = head;
    while(secondLastNode->next->next != NULL) {
        secondLastNode = secondLastNode->next;
    }
    // secondLastNode points to the second last node of the Linked List
    Node* toDelete = secondLastNode->next;
    secondLastNode->next = NULL;
    delete toDelete;
}

// Deletion at a given position of the Linked List:
void deleteAtPosition(Node* &head, int pos) {
    // if pos=0, deleteAtBeginning
    if(pos == 0) {
        deleteAtBeginning(head);
        return;
    }
    // pos>0
    Node* prev = head;
    int currentPos = 0; // we consider the head node to be at position 0
    while(currentPos != pos-1) {
        prev = prev->next;
        currentPos++;
    }
    // prev points to the (pos-1)th node of the Linked List
    Node* toDelete = prev->next;
    prev->next = prev->next->next;
    delete toDelete;
}

int main() {
    // Create a Linked List
    Node* head = NULL;
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 4);
    display(head);  // 4->3->2->1->NULL

    // Delete at the beginning
    // deleteAtBeginning(head);
    // display(head);  // 3->2->1->NULL

    // Delete at the end
    // deleteAtEnd(head);
    // display(head);  // 4->3->2->NULL

    // Delete at a given position
    deleteAtPosition(head, 2);
    display(head);  // 4->3->1->NULL
    
    return 0;
}
