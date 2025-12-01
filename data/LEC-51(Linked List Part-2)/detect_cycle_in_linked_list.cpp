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
bool detectCycle(Node* head){
    if (!head){
        return false;
    }

    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow){
            cout<<"Both Pointer Meets at: "<<slow->data<<endl;
            return true;
        }
    }
    return false;
}

// Remove Cycle: Point the last node to NULL
void removeCycle(Node* &head){  // assuming that the linked list has a cycle
    Node* slow = head;
    Node* fast = head;

    // Here we have to use do-while loop, at starting both points towards 1;
    do{
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    // Now slow and fast both points to 7

    // 
    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    // Now slow points 8(Last node of the linked list)
    slow->next = NULL;
}

int main() {
    // Create a Linked List Which have cycle inside it:
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.insert(7);
    ll.insert(8);
    ll.head->next->next->next->next->next->next->next->next = ll.head->next->next;

    // Detect if Cycle is present or not:
    cout<<detectCycle(ll.head)<<endl;;

    // Remove the cycle:
    cout<<"After Removing Cycle------>"<<endl;;
    removeCycle(ll.head);
    ll.display();

    return 0;
}

    // 1->2->3->4->5->6->7->8
    //       ^              |
    //       |              |
    //       |_ _ _ _ _ _ __|