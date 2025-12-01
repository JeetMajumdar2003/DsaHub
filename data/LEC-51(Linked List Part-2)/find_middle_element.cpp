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
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
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

// Find Middle Element of a Linked List: Using Slow and Fast Pointers
Node* findMiddleElement(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    // Create two linked lists with an intersection node
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(5);
    // 1->2->3->4->5->NULL

    // Display the elements of the list
    list1.display();

    // Find Middle Element of a Linked List: Using Slow and Fast pointers
    Node* middleNode = findMiddleElement(list1.head);
    cout<<middleNode->data;

    return 0;
}
