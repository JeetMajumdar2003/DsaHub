#include<iostream>
using namespace std;

// Node class
class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

// Queue class
class Queue {
    Node* front;
    Node* rear;
    int size = 0;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if(front == NULL && rear == NULL) {
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Function to remove an element from the queue
    void dequeue() {
        Node* temp = front;
        if(front == NULL) {
            cout << "Queue is Empty" << endl;
            return;
        }
        if(front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
        }
        delete temp;
        size--;
    }

    // Function to get the front element of the queue
    int getFront() {
        if(front == NULL) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Function to get the size of the queue
    int getSize() {
        return size;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == NULL;
    }

    // Function to display the elements of the queue
    void display() {
        Node* temp = front;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    cout << "Front element: " << q.getFront() << endl;
    cout << "Size of the queue: " << q.getSize() << endl;
    q.dequeue();
    q.display();
    cout << "Front element: " << q.getFront() << endl;
    cout << "Size of the queue: " << q.getSize() << endl;
    return 0;
}