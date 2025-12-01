#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    bool visited;

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
        visited = false;
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

// M-1: Find the intersection node of two linked lists
Node* findIntersection(LinkedList list1, LinkedList list2) {
    Node* temp1 = list1.head;
    Node* temp2 = list2.head;

    while (temp1 != NULL) {
        temp1->visited = true;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        if (temp2->visited == true) {
            return temp2;
        }
        temp2 = temp2->next;
    }

    return NULL;
}

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

// Move the head pointer of a linked list by the difference in length
Node* moveHead(Node* head, int k) {
    Node* temp = head;
    while (k--) {
        temp = temp->next;
    }
    return temp;
}

// M-2: Find the intersection node of two linked lists
Node* getInterscectionNode(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    // Step-1: Get the length of the two lists
    int len1 = getLength(temp1);
    int len2 = getLength(temp2);

    // Step-2: Get the difference in length
    int diff = abs(len1 - len2);

    // Step-3: Move the pointer of the longer list by the difference
    if (len1 > len2) { // list1 is longer
        temp1 = moveHead(temp1, diff);
    } else { // list2 is longer
        temp2 = moveHead(temp2, diff);
    }

    // Step-4: Move the pointers of the two lists until they meet
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;
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

    LinkedList list2;
    list2.insert(6);
    list2.insert(7);
    list2.head->next->next = list1.head->next->next->next;
    // 6->7->3->4->5->NULL

    // // Create an intersection node
    // Node* intersection = new Node(7);
    // list1.head->next->next->next = intersection;
    // list2.head->next->next = intersection;

    // Display the lists
    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    // M-1: Find the intersection node
    // Node* intersectionNode = findIntersection(list1, list2);
    // if (intersectionNode != NULL) {
    //     cout << "Intersection node: " << intersectionNode->data << endl;
    // } else {
    //     cout << "No intersection node" << endl;
    // }

    // M-2: Find the intersection node
    Node* intersectionNode = getInterscectionNode(list1.head, list2.head);
    if (intersectionNode != NULL) {
        cout << "Intersection node: " << intersectionNode->data << endl;
    } else {
        cout << "No intersection node" << endl;
    }

    

    return 0;
}
