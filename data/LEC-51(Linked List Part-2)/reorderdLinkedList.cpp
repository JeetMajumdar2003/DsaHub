#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Linked list class
class LinkedList {
    
public:
// private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    public:
    Node* getHead() const {
        return head;
    }

    // Insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display the elements of the list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<< "NULL" << endl;
    }
};

// Reorder the Linked List:
// 1->2->3->4->5->6->7->8->9
// 1->9->2->8->3->7->4->6->5
Node* reorderList(Node* &head) {
    // 1. Find the middle of the list
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // At this point, slow is pointing to the middle of the list

    // 2. Reverse the second half of the list:
    Node* prev = slow;
    Node* curr = slow->next;
    slow->next = NULL;
    Node* nextPtr = NULL;
    while (curr != NULL) {
        nextPtr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextPtr;
    }
    // At this point, prev is pointing to the last node of the list

    // 3. Merge the two lists:
    Node* head1 = head; // head1 is the head of the first half of the list
    Node* head2 = prev; // head2 is the head of the second half of the list
    Node* temp = NULL;  
    while (head2->next != NULL) {
        temp = head1->next;
        head1->next = head2;
        head1 = temp;

        temp = head2->next;
        head2->next = head1;
        head2 = temp;
    }
    // OR
    // while (head1!=head2) {
    //     temp = head1->next;
    //     head1->next = head2;
    //     head1 = head2;
    //     head2 = temp;
    // }
    return head;
}

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    // list.insert(6);
    list.display();

    // Reorder the Linked List
    reorderList(list.head);
    list.display();
    return 0;
}