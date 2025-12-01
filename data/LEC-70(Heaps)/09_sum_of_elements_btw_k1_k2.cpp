#include <iostream>
using namespace std;

// 0 based indexing
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

int sumOfElementsBetweenK1K2(int heap[], int size, int k1, int k2){
    // Build min heap
    for (int i = size / 2 - 1; i >= 0; i--){
        minHeapify(heap, size, i);
    }

    int sum = 0;
    int elements = k2 - k1 - 1;

    // Delete k1 elements, now the root will be kth smallest element
    while (k1--){
        swap(heap[0], heap[size - 1]);
        size--;
        minHeapify(heap, size, 0);
    }

    // Add k2-k1-1 elements to sum
    while (elements--){
        sum += heap[0];
        swap(heap[0], heap[size - 1]);
        size--;
        minHeapify(heap, size, 0);
        
    }

    return sum;
}

int main(){
    int heap[] = {20, 8, 22, 4, 12, 10, 14};
    int size = 7;

    cout << "Enter the value of k1 and k2: ";
    int k1, k2;
    cin >> k1 >> k2;

    // 4 8 10 12 14 20 22   (1 based indexing position)
    cout << "Sum of elements between k1 and k2 is: ";
    int ansSum = sumOfElementsBetweenK1K2(heap, size, k1, k2);
    cout << ansSum;

    return 0;
}