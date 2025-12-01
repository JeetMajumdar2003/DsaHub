#include <iostream>
using namespace std;
int n = 100;

// Function to Delete element in Min Heap
void deleteInMinHeap(int minHeap[], int &size) {
    // Deleting Root element
    minHeap[1] = minHeap[size];
    size--;

    int current = 1;
    int leftChild = 2 * current;
    int rightChild = 2 * current + 1;

/*
    // while (leftChild <= size) {
    //     int smallest = current;

    //     if (minHeap[leftChild] < minHeap[current]) {
    //         smallest = leftChild;
    //     }

    //     if (rightChild <= size && minHeap[rightChild] < minHeap[smallest]) {
    //         smallest = rightChild;
    //     }

    //     if (smallest == current) {
    //         return;
    //     }

    //     swap(minHeap[current], minHeap[smallest]);
    //     current = smallest;
    //     leftChild = 2 * current;
    //     rightChild = 2 * current + 1;
    // }
*/
    
    while(leftChild <= size) {
        int minChild = (minHeap[leftChild] < minHeap[rightChild]) ? leftChild : rightChild;

        if(minHeap[current] <= minHeap[minChild]) {
            return;
        }

        swap(minHeap[current], minHeap[minChild]);

        current = minChild;
        leftChild = 2 * current;
        rightChild = 2 * current + 1;
    }

    cout << "Element deleted successfully!" << endl;
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
    int minHeap[n] = {-1, 5, 10, 20, 30, 40, 50, 60};
    int size = 7;

    printHeap(minHeap, size);

    deleteInMinHeap(minHeap, size);

    // Printing Min Heap
    printHeap(minHeap, size);
    return 0;
}