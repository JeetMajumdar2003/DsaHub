#include<iostream>
#include<vector>
using namespace std;

class Queue {
    int front, rear, size;
    unsigned capacity;
    vector<int> arr;
public:
    Queue(unsigned c) {
        this->capacity = c;
        front = this->size = 0;
        rear = capacity - 1;
        arr.resize(capacity);
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        if(isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;   // or rear++;
        arr[rear] = data;
        size++;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if(isEmpty()) { //or (front == rear)
            cout << "Queue is Empty" << endl;
            front = rear = -1;
            arr.clear();    // used to clear the vector because the front and rear are -1
            return;
        }
        front = (front + 1) % capacity; // or front++;
        size--;
    }

    // Function to get the front element of the queue
    int getFront() {
        if(isEmpty()) { //or (front == rear)
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to get the rear element of the queue
    int getRear() {
        if(isEmpty()) { //or (front == rear)
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (size == capacity);
    }

    // Function to get the size of the queue
    int getSize() {
        return size;
    }

    // Function to print the queue
    void printQueue() {
        for(int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.printQueue();
    q.dequeue();
    q.printQueue();
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Size of the queue: " << q.getSize() << endl;
    cout << "Is the queue empty? " << q.isEmpty() << endl;
    cout << "Is the queue full? " << q.isFull() << endl;
    q.dequeue();
    q.dequeue();
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Size of the queue: " << q.getSize() << endl;
    cout << "Is the queue empty? " << q.isEmpty() << endl;
    cout << "Is the queue full? " << q.isFull() << endl;
    q.dequeue();
    q.dequeue();
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Size of the queue: " << q.getSize() << endl;
    cout << "Is the queue empty? " << q.isEmpty() << endl;
    cout << "Is the queue full? " << q.isFull() << endl;
    q.dequeue();
    return 0;
}