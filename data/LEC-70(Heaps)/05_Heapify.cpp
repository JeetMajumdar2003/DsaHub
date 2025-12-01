#include <iostream>
using namespace std;
int n = 100;

// Function to heapify the array(Converting an array into a min heap):
void minHeapify(int heap[], int size, int current) {

    // iterate till the current node is not a leaf node
    while(2*current <= size) {  // 2*current <= size (current node has atleast one child)
        int leftChildIdx = 2*current;
        int rightChildIdx = 2*current + 1;
        int minChildIdx = leftChildIdx; // Assuming left child is the smallest

        // Check if right child is smaller than left child
        if(rightChildIdx <= size && heap[rightChildIdx] < heap[minChildIdx]) {
            minChildIdx = rightChildIdx;
        }

        // Check if the current node is smaller than the smallest child
        if(heap[minChildIdx] >= heap[current]) {
            return;
        }

        // Swap the current node with the smallest child
        swap(heap[current], heap[minChildIdx]);
        // Update the current node
        current = minChildIdx;
    }

    return;
}

// Function to heapify the array(Converting an array into a max heap):
void maxHeapify(int heap[], int size, int current) {

    // iterate till the current node is not a leaf node
    while(2*current <= size) {  // 2*current <= size (current node has atleast one child)
        int leftChildIdx = 2*current;
        int rightChildIdx = 2*current + 1;
        int maxChildIdx = leftChildIdx; // Assuming left child is the largest

        // Check if right child is larger than left child
        if(rightChildIdx <= size && heap[rightChildIdx] > heap[maxChildIdx]) {
            maxChildIdx = rightChildIdx;
        }

        // Check if the current node is larger than the largest child
        if(heap[maxChildIdx] <= heap[current]) {
            return;
        }

        // Swap the current node with the largest child
        swap(heap[current], heap[maxChildIdx]);
        // Update the current node
        current = maxChildIdx;
    }

    return;
}

// Print Heap
void printHeap(int heap[], int size) {
    for (int i = 1; i <= size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    // Heapify: Convert an array/tree into a min heap
    int heap[] = {0, 60, 10, 80, 50, 5, 20, 70};
    int size = 7;

    // Heapify(Start from the last non-leaf node(n/2) to the root node(1) and heapify the array)
    // for(int i = size/2; i >= 1; i--) {
    //     minHeapify(heap, size, i);
    // }
    // cout << "Min Heap: ";
    // printHeap(heap, size);

    // Heapify(Start from the last non-leaf node(n/2) to the root node(1) and heapify the array)
    for(int i = size/2; i >= 1; i--) {
        maxHeapify(heap, size, i);
    }
    cout << "Max Heap: ";
    printHeap(heap, size);
    return 0;
}

/**
 * 1. Heapify: Convert an array/tree into a min heap or max heap
 * 2. In Binary Heap: leaf nodes start from n/2 + 1 to n (n is the size of the heap)
 * 3. last non-leaf node(parent node of the last node) = n/2
 * 4. Start from the last non-leaf node(n/2) to the root node(1) and heapify the array
 */