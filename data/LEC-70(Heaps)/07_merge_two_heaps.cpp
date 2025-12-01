#include <iostream>
using namespace std;

void Heapify(int heap[], int size, int current) {
    while (2 * current <= size) {
        int leftChildIdx = 2 * current;
        int rightChildIdx = 2 * current + 1;
        int maxChildIdx = leftChildIdx;

        if (rightChildIdx <= size && heap[rightChildIdx] > heap[maxChildIdx]) {
            maxChildIdx = rightChildIdx;
        }

        if (heap[maxChildIdx] <= heap[current]) {
            return;
        }

        swap(heap[current], heap[maxChildIdx]);
        current = maxChildIdx;
    }

    return;
}

int* mergeTwoHeaps(int heap1[], int size1, int heap2[], int size2) {
    int size = size1 + size2;
    int* mergedHeap = new int[size];    // we need to use new keyword to allocate memory dynamically(at runtime) for the merged heap we can also use [static int mergedHeap[100];] but it is not recommended

    for (int i = 1; i <= size1; i++) {
        mergedHeap[i] = heap1[i];
    }

    for (int i = 1; i <= size2; i++) {
        mergedHeap[size1 + i] = heap2[i];
    }

    for (int i = size / 2; i >= 1; i--) {
        Heapify(mergedHeap, size, i);
    }

    return mergedHeap;
}

// Print Heap
void printHeap(int heap[], int size) {
    for (int i = 1; i <= size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int heap1[] = {0, 60, 10, 80, 50, 5, 20, 70};
    int size1 = 7;
    int heap2[] = {0, 30, 40, 90, 100, 110};
    int size2 = 5;

    // Merge two heaps
    int* mergedHeap = mergeTwoHeaps(heap1, size1, heap2, size2); // store the address of the merged heap in a pointer called mergedHeap

    // Print the merged heap
    printHeap(mergedHeap, size1 + size2);

    // Free the dynamically allocated memory
    delete[] mergedHeap;

    return 0;
}