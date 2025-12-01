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

// Rotate the linked list by k nodes:

// 1. Brute force approach: O(k*n)
Node* rotateLinkedListBruteForce(Node* &head, int k) {
    // Base case
    if (head == NULL || head->next == NULL || k==0) {
        return head;
    }

    // Rotate the linked list k times
    for (int i = 0; i < k; i++) {
        // Move to the last node
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        // Move the last node to the front
        temp->next->next = head;
        head = temp->next;
        temp->next = NULL;
    }

    return head;
    
}

// 2. Efficient approach: O(n)
Node* rotateLinkedListEfficient(Node* &head, int k) {
    // Base case
    if (head == NULL || head->next == NULL || k==0) {
        return head;
    }

    // Find the length of the linked list
    Node* temp = head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    cout<<length<<endl;
    // temp is at the last node

    // Make the linked list circular
    temp->next = head;

    // Move to the kth node from the end
    k = k % length;
    for (int i = 0; i < length-k; i++) {
        temp = temp->next;
    }
    // temp is at the (n-k)th node

    // Make the next node as the head
    head = temp->next;

    // Break the circular linked list
    temp->next = NULL;

    return head;
}

int main() {
    // Create linked lists
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.display();
    
    // Rotate the linked list
    // 1. Brute force approach
    // Node* newHead = rotateLinkedListBruteForce(list.head, 2);
    // list.head = newHead;
    // list.display();

    // 2. Efficient approach
    Node* newHead2 = rotateLinkedListEfficient(list.head, 2);
    list.head = newHead2;
    list.display();
    return 0;
}
