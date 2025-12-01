#include<iostream>
using namespace std;

// Node class
class Node {    
    public:
        int data;
        Node* next;
        // Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        // prev = NULL;
    }
};

// Circular Linked List class
class CircularLinkedList {
    public:
        Node* head;
    
    CircularLinkedList() {
        head = NULL;
    }

    // Display the list
    void display(){
        Node* temp = head;
        do{
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout<<endl;
    }

    void checkCircular(){
        Node* temp = head;
        for (int i = 0; i < 10; i++){
            cout<<temp->data<<"->";
            temp = temp->next;
        }cout<<endl;
        return;
    }

    // Insert at the begining:
    void insertAtBegining(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            new_node->next = head;
            return;
        }
        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        // Now tail is pointing to the last node:
        tail->next = new_node;
        new_node->next = head;
        head = new_node;
        return;
    }

    // Insert at the End:
    void insertAtEnd(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            new_node->next = head;
            return; 
        }
        Node* tail = head;
        while (tail->next != head){
            tail = tail->next;
        }
        // Now tail is pointing to the last node:
        tail->next = new_node;
        new_node->next = head;
        return;
    }

    // Delete from the begining:
    void deleteAtBegining(){
        if(head == NULL) return;
        Node* temp = head;
        Node* tail = head;
        while (tail->next != head){
            tail = tail->next;
        }
        // Now tail is pointing to the last node:
        head = head->next;
        tail->next = head;
        free(temp);
        return;
    }

    // Delete from the End:
    void deleteAtEnd(){
        if(head == NULL) return;
        Node* tail = head;
        while (tail->next->next != head){
            tail = tail->next;
        }
        // Now tail is pointing to the 2nd last node:
        Node* temp = tail->next;
        tail->next = head;
        free(temp);
        return;
    }
};

int main(){
    CircularLinkedList cll;

    // Insert at the Start:
    cll.insertAtBegining(3);
    cll.insertAtBegining(2);
    cll.insertAtBegining(1);
    cll.display();

    // Insert at the Start:
    cll.insertAtEnd(4);
    cll.insertAtEnd(5);
    cll.insertAtEnd(6);
    cll.display();

    // Delete from the begining:
    cll.deleteAtBegining(); 
    cll.deleteAtBegining();
    cll.display();

    // Delete from the End:
    cll.deleteAtEnd(); 
    cll.deleteAtEnd();
    cll.display();

    cll.checkCircular();
    return 0;
}