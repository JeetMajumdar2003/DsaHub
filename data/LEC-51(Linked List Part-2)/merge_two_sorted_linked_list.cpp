#include <iostream>
using namespace std;

// Node Class
class Node {
   public:
    int val;
    Node* next;

    // Constructor
    Node(int data) {
        val = data;
        next = NULL;
    }
};

// Linked List Class
class LinkedList {
   public:
    Node* head;

    // Constructor
    LinkedList() {
        this->head = nullptr;
    }

    // Insert
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = this->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display
    void display() {
        Node* temp = this->head;
        while (temp != nullptr) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Merge Two Sorted Linked List:(Without Creating new linkedlist)
Node* mergeSortLL(Node* head1, Node* head2){
    Node* dummyNode = new Node(-1); 
    Node* ptr3 = dummyNode;

    // if (head1->val <= head2->val){
    //     newHead = head1;
    //     ptr3 = head1;
    //     head1 = head1->next;
    // }
    // else{
    //     newHead = head2;
    //     ptr3 = head2;
    //     head2 = head2->next;
    // }
    

    Node* temp1 = head1;
    Node* temp2 = head2;

    // Compare 
    while (temp1 != NULL && temp2 != NULL){
        if (temp1->val <= temp2->val){
            ptr3->next = temp1;
            temp1 = temp1->next;
        }
        else{
            ptr3->next = temp2;
            temp2 = temp2->next;
        }
        ptr3 = ptr3->next;
    }

    if (temp1 != NULL){
        ptr3->next = temp1;
        // temp1 = temp1->next;
        // ptr3 = ptr3->next;
    }
    else{
        ptr3->next = temp2;
        // temp2 = temp2->next;
        // ptr3 = ptr3->next;
    }
    
    Node* newHead = dummyNode->next;
    return newHead;
}

int main(){
    // Create two linked list
    LinkedList l1;
    l1.insert(1);
    l1.insert(4);
    l1.insert(7);
    l1.insert(8);

    LinkedList l2;
    l2.insert(3);
    l2.insert(5);
    l2.insert(6);

    // Print the linked list
    l1.display();
    l2.display();

    LinkedList l3;
    l3.head = mergeSortLL(l1.head, l2.head);

    l3.display();

    return 0;
}