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

// M-1: Remove the kth node from the end of a linked list using two pointers
void removeKthNodeFromEnd(Node* &head, int k) {
    // Create two pointers
    Node* first = head;
    Node* second = head;

    // Move the second pointer k nodes ahead
    int count = 1;
    while (count <= k) {
        second = second->next;
        count++;
    }
    // Now, the second pointer is k nodes ahead of the first pointer

    // If the second pointer is NULL, it means that the kth node from the end is the head node
    if (second == NULL) {
        // Remove the head node
        head = head->next;
        return;
    }

    // Move both pointers until the second pointer reaches the end of the list
    while (second->next != NULL) {
        first = first->next;
        second = second->next;
    }

    // Now, the first pointer is pointing to the node before kth node from the end
    // Remove the kth node from the end = first->next
    first->next = first->next->next;

    return;
}

// M-2: Remove the kth node from the end of a linked list using length of the list
// Get the length of a linked list:
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Remove the kth node from the beginning of a linked list
void removeKthNodeFromBeginning(Node* &head, int k) {
    // If k is 1, remove the head node
    if (k == 1) {
        // Remove the head node
        head = head->next;
        return;
    }

    // If k is greater than 1, remove the node at the given position
    Node* temp = head;
    int count = 1;
    // Move temp pointer to the node before the node to be removed
    while (count < k - 1) {
        temp = temp->next;
        count++;
    }
    // Now, temp is pointing to the node before the node to be removed
    Node* nodeToBeRemoved = temp->next;
    temp->next = temp->next->next;
    free(nodeToBeRemoved);
}

void removeKthNodeFromEnd2(Node* &head, int k) {
    // Get the length of the list
    int length = getLength(head);

    // If k is greater than the length of the list, return
    if (k > length) {
        return;
    }

    // If k is equal to the length of the list, remove the head node
    if (k == length) {
        // Remove the head node
        head = head->next;
        return;
    }

    // If k is less than the length of the list, find the position of the node to be removed from the beginning
    int position = length - k + 1;

    // Remove the node at the given position
    removeKthNodeFromBeginning(head, position);
    return;
}


int main() {
    // Create two linked lists with an intersection node
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(5);
    list1.insert(6);
    // 1->2->3->4->5->6->NULL

    // Display the elements of the list
    list1.display();

    // Remove the kth node from the end of the list: Using two pointers
    removeKthNodeFromEnd(list1.head, 3);

    // M-2: Using length of the list
    // removeKthNodeFromEnd2(list1.head, 3);

    // Display the elements of the list
    list1.display();

    return 0;
}
