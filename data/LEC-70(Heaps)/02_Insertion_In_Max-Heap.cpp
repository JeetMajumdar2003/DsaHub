#include <iostream>
using namespace std;
int n = 100;

// Function to insert element in Max Heap
void insertInMaxHeap(int maxHeap[], int size, int element) {
    size++;
    maxHeap[size] = element;

    int current = size;
    int parent = current / 2;

    while (maxHeap[parent] < maxHeap[current] && current > 1) {
        swap(maxHeap[parent], maxHeap[current]);
        current = parent;
        parent = current / 2;
    }

    cout << "Element inserted successfully!" << endl;
}


// Print Heap
void printHeap(int heap[], int size) {
    for (int i = 1; i <= size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    // Max Heap: Root element is the Maximum element
    int maxHeap[n] = {-1, 50, 40, 30, 20, 10};


    // Inserted element: 60
    int element = 60;
    // Inserting element in Max Heap
    int size = 5;

    printHeap(maxHeap, size);

    insertInMaxHeap(maxHeap, size, element);

    // Printing Max Heap
    printHeap(maxHeap, size + 1);
    return 0;
}