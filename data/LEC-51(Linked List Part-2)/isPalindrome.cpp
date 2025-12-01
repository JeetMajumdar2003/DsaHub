#include<iostream>
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

bool isPalindrome(Node* head) {
    // 1. Find the middle element
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Now slow is pointing to the middle node

    // 2. Break the list into two parts in the middle
    Node* currNode = slow->next;
    Node* prevNode = slow;
    slow->next = NULL;

    // 3. Reverse the second half of the list
    while (currNode) {
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    // Now prevNode is pointing to the last node of the list, which is the new head of the reversed list

    // 4. Compare the two lists
    Node* head1 = head;
    Node* head2 = prevNode;

    while (head1 && head2) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main() {
    // Create a linked list
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(2);
    list.insert(1);

    // Display the original list
    cout << "Original list: " << endl;
    list.display();

    // Check if the list is a palindrome
    if (isPalindrome(list.head)) {
        cout << "The list is a palindrome" << endl;
    } else {
        cout << "The list is not a palindrome" << endl;
    }
}