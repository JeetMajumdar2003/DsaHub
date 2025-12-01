#include <iostream>
using namespace std;

// Function to heapify the array(Converting an array into a max heap):
void maxHeapify(int heap[], int size, int current) {

    while(2*current <= size) {
        int leftChildIdx = 2*current;
        int rightChildIdx = 2*current + 1;
        int maxChildIdx = leftChildIdx;

        if(rightChildIdx <= size && heap[rightChildIdx] > heap[maxChildIdx]) {
            maxChildIdx = rightChildIdx;
        }

        if(heap[maxChildIdx] <= heap[current]) {
            return;
        }

        swap(heap[current], heap[maxChildIdx]);
        current = maxChildIdx;
    }

    return;
}

// Heap Sort Algorithm:
void heapSort(int heap[], int size) {
    // Step 1: Convert the array into a max heap using maxHeapify
    for(int i = size/2; i >= 1; i--) {
        maxHeapify(heap, size, i);
    }

    // Step 2: Swap the first element with the last element and reduce the size of the heap by 1
    // Step 3: Heapify the array again using maxHeapify
    // Step 4: Repeat the above steps until the size of the heap is greater than 1
    while(size > 1) {
        swap(heap[1], heap[size]);
        size--;
        maxHeapify(heap, size, 1);
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
    int heap[] = {0, 60, 10, 80, 50, 5, 20, 70};
    int size = 7;

    // Heap Sort Algorithm:
    // Step 1: Convert the array into a max heap using maxHeapify
    // Step 2: Swap the first element with the last element and reduce the size of the heap by 1
    // Step 3: Heapify the array again using maxHeapify
    // Step 4: Repeat the above steps until the size of the heap is greater than 1
    heapSort(heap, size);

    // Print the sorted heap
    cout<<"Sorted Heap: ";
    printHeap(heap, size);
    return 0;
}

/**
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 */