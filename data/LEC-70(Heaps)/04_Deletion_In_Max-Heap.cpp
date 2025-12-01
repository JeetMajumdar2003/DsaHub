#include <iostream>
using namespace std;
int n = 100;

// Function to Delete element in Max Heap
void deleteInMaxHeap(int maxHeap[], int &size) {
    // Deleting Root element
    maxHeap[1] = maxHeap[size];
    size--;

    int current = 1;
    int leftChild = 2 * current;
    int rightChild = 2 * current + 1;

/*
    // while (leftChild <= size) {
    //     int smallest = current;

    //     if (maxHeap[leftChild] < maxHeap[current]) {
    //         smallest = leftChild;
    //     }

    //     if (rightChild <= size && maxHeap[rightChild] < maxHeap[smallest]) {
    //         smallest = rightChild;
    //     }

    //     if (smallest == current) {
    //         return;
    //     }

    //     swap(maxHeap[current], maxHeap[smallest]);
    //     current = smallest;
    //     leftChild = 2 * current;
    //     rightChild = 2 * current + 1;
    // }
*/
    
    while(leftChild <= size) {
        int MaxChild = (maxHeap[leftChild] > maxHeap[rightChild]) ? leftChild : rightChild;

        if(maxHeap[current] >= maxHeap[MaxChild]) {
            cout << "Element deleted successfully!" << endl;
            return;
        }

        swap(maxHeap[current], maxHeap[MaxChild]);

        current = MaxChild;
        leftChild = 2 * current;
        rightChild = 2 * current + 1;
    }

    cout << "Element deleted successfully!" << endl;

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
    // Max Heap: Root element is the Maximum element
    int maxHeap[n] = {-1, 90, 80, 70, 20, 10, 60, 50};
    int size = 7;

    printHeap(maxHeap, size);

    deleteInMaxHeap(maxHeap, size);

    // Printing Max Heap
    printHeap(maxHeap, size);
    return 0;
}