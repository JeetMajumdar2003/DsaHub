#include <iostream>
using namespace std;
int n = 100;

// Function to insert element in Min Heap
void insertInMinHeap(int minHeap[], int size, int element) {
    size++;
    minHeap[size] = element;

    int current = size;
    int parent = current / 2;

    while (minHeap[parent] > minHeap[current] && current > 1) {
        swap(minHeap[parent], minHeap[current]);
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
    // Min Heap: Root element is the minimum element
    int minHeap[n] = {-1, 10, 20, 30, 40, 50};


    // Inserted element: 5
    int element = 5;
    int size = 5;

    printHeap(minHeap, size);

    // Inserting element in Min Heap
    insertInMinHeap(minHeap, size, element);

    // Printing Min Heap
    printHeap(minHeap, size + 1);
    return 0;
}