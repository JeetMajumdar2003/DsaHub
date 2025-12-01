#include <iostream>
using namespace std;

void minHeapify(int heap[], int size, int current){
    while (2 * current + 1 < size){
        int leftChildIdx = 2 * current + 1;
        int rightChildIdx = 2 * current + 2;
        int minChildIdx = leftChildIdx;

        if (rightChildIdx < size && heap[rightChildIdx] < heap[leftChildIdx]){
            minChildIdx = rightChildIdx;
        }

        if (heap[minChildIdx] >= heap[current]){
            return;
        }

        swap(heap[current], heap[minChildIdx]);
        current = minChildIdx;
    }

    return;
}

int kThSmallest(int heap[], int size, int k){
    // Build min heap
    for (int i = size / 2 - 1; i >= 0; i--){
        minHeapify(heap, size, i);
    }

    // Delete k-1 elements, now the root will be kth smallest element
    while (k > 1){
        swap(heap[0], heap[size - 1]);
        size--;
        minHeapify(heap, size, 0);
        k--;
    }

    return heap[0];
}

int main(){
    int heap[] = {7, 10, 4, 3, 20, 15};
    int size = 6;

    cout << "Enter the value of k: ";
    int k;
    cin >> k;

    cout << "Kth smallest element is: ";
    cout << kThSmallest(heap, size, k);

    return 0;
}