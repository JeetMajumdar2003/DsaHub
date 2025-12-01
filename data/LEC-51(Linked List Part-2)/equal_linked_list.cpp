
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

// Check if two linked lists are equal: iterative approach
bool isEqualIterative(Node* head1, Node* head2) {
    // Create two temporary pointers
    Node* temp1 = head1;
    Node* temp2 = head2;

    // Traverse both lists and compare their data
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    // at this point, either temp1 or temp2 is NULL, or both are NULL
    // If both are NULL, the lists are equal
    return (temp1 == NULL && temp2 == NULL);
}

int main() {
    // Create two linked lists
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);

    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(3);
    list2.insert(4);

    // Display the lists
    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();


    // Check if the lists are equal: 
    if (isEqualIterative(list1.getHead(), list2.getHead())) {
        cout << "The lists are equal." << endl;
    } else {
        cout << "The lists are not equal." << endl;
    }
    /**
     * here list1.head and list2.head are not working as head is declared private in LinkedList class.
     * so we have to use getHead() function to get the head of the list.
    */
    if (isEqualIterative(list1.head, list2.head)) {
        cout << "The lists are equal." << endl;
    } else {
        cout << "The lists are not equal." << endl;
    }

    return 0;
}
