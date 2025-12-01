#include<iostream>
using namespace std;

// Node class
class Node {    
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
    public:
        Node* head;
        Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Display the Doubly Linked List:
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Inesert at the Begining:
    void insertAtBegining(int val){
        Node* new_node = new Node(val);
        // If the Linked List is empty:
        if(head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    // Insert at the End:
    void insertAtEnd(int val){
        Node* new_node = new Node(val);
        // If the Linked List is empty:
        if(tail == NULL){   // OR head == NULL
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    // Insert at a given(K-th) position:
    void insertAtK(int val, int k){
        Node* new_node = new Node(val);
        // If the Linked List is empty:
        if(head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        // If the position is 1:
        if(k == 1){
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            return;
        }
        // If the position is lesser than the length of the Linked List:
        Node* temp = head;
        int pos = 1;
        while(temp != NULL && pos < k-1){
            temp = temp->next;
            pos++;
        }
        // If k is greater than the length of the Linked List:
        if(temp == NULL){
            cout << "The Linked List is not that long!" << endl;
            return;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
        if(new_node->next != NULL){
            new_node->next->prev = new_node;
        }
        else{
            tail = new_node;
        }
        return;
    }

    // Delete at the Begining:
    void deleteAtBegining(){
        // If the Linked List is empty:
        if(head == NULL){
            cout << "The Linked List is empty!" << endl;
            return;
        }
        // // If the Linked List has only one node:
        // if(head->next == NULL){
        //     delete head;
        //     head = NULL;
        //     tail = NULL;
        //     return;
        // }
        // Node* temp = head;
        // head = head->next;
        // head->prev = NULL;
        
        // More efficient way:
        Node* temp = head;
        head = head->next;
        // If the Linked List has only one node: that means now head is pointing to NULL
        if(head == NULL){
            tail = NULL;
        }
        else{
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    // Delete at the End:
    void deleteAtEnd(){
        // If the Linked List is empty:
        if(tail == NULL){
            cout << "The Linked List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        // If the Linked List has only one node: that means now tail is pointing to NULL
        if(tail == NULL){
            head = NULL;
        }
        else{
            tail->next = NULL;
        }
        free(temp);
        return;
    }

    // Delete at a given(K-th) position:
    void deleteAtK(int k){
        // If the Linked List is empty:
        if(head == NULL){
            cout << "The Linked List is empty!" << endl;
            return;
        }
        // If the position is 1:
        if(k == 1){
            Node* temp = head;
            head = head->next;
            // If the Linked List has only one node: that means now head is pointing to NULL
            if(head == NULL){
                tail = NULL;
            }
            else{
                head->prev = NULL;
            }
            free(temp);
            return;
        }
        // If the position is less than the length of the Linked List:
        Node* temp = head;
        int pos = 1;
        while(temp != NULL && pos < k){
            temp = temp->next;
            pos++;
        }
        // If k is greater than the length of the Linked List:
        if(temp == NULL){
            cout << "The Linked List is not that long!" << endl;
            return;
        }
        temp->prev->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = temp->prev;
        }
        else{
            tail = temp->prev;
        }
        free(temp);
        return;
    }
};

int main(){
    DoublyLinkedList dll;

    // Insert at the Begining:
    dll.insertAtBegining(3);
    dll.insertAtBegining(2);
    dll.insertAtBegining(1);
    dll.display();

    // Insert at the End:
    dll.insertAtEnd(4);
    dll.insertAtEnd(5);
    dll.insertAtEnd(6);
    dll.display();

    // Insert at a given(K-th) position: 1 based indexing
    dll.insertAtK(7, 3);
    dll.insertAtK(8, 4);
    dll.display();

    // Delete at the Begining:
    dll.deleteAtBegining();
    dll.deleteAtBegining();
    dll.display();

    // Delete at the End:
    dll.deleteAtEnd();
    dll.deleteAtEnd();
    dll.display();

    // Delete at a given(K-th) position: 1 based indexing
    dll.deleteAtK(3);
    dll.deleteAtK(2);
    dll.display();

    // Display the Doubly Linked List:
    dll.display();
    return 0;

}