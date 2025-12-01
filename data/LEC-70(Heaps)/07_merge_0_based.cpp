//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Fix: Pass vectors by value instead of non-const reference
class Solution {
public:
    void heapify(vector<int> &mergedHeap, int size, int current) {
        while (2 * current + 1 < size) {
            int leftChildIdx = 2 * current + 1;
            int rightChildIdx = 2 * current + 2;
            int maxChildIdx = leftChildIdx;

            if (rightChildIdx < size && mergedHeap[rightChildIdx] > mergedHeap[maxChildIdx]) {
                maxChildIdx = rightChildIdx;
            }

            if (mergedHeap[maxChildIdx] <= mergedHeap[current]) {
                return;
            }

            swap(mergedHeap[current], mergedHeap[maxChildIdx]);
            current = maxChildIdx;
        }

        return;
    }

    vector<int> mergeHeaps(vector<int> a, vector<int> b, int n, int m) {
        vector<int> mergedHeap; // 0 based indexing

        for (int x : a) {
            mergedHeap.push_back(x);
        }
        for (int x : b) {
            mergedHeap.push_back(x);
        }

        int lastIndex = m + n - 1;
        int lastParentNode = lastIndex / 2;
        for (int i = lastParentNode; i >= 0; i--) {
            heapify(mergedHeap, m + n, i);
        }
        return mergedHeap;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged) {
    if (arr1.size() + arr2.size() != merged.size()) {
        return false;
    }
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    sort(arr1.begin(), arr1.end());
    vector<int> mergedCopy = merged;
    sort(mergedCopy.begin(), mergedCopy.end());
    if (arr1 != mergedCopy) {
        return false;
    }
    for (int i = 1; i < merged.size(); i++) {
        if (merged[i] > merged[(i - 1) / 2])
            return false;
    }
    return true;
}

int main() {
    int heap1[] = {60, 10, 80, 50, 5, 20, 70};
    int size1 = 7;
    int heap2[] = {30, 40, 90, 100, 110};
    int size2 = 5;

    // Merge two heaps
    Solution obj;
    vector<int> mergedHeap = obj.mergeHeaps(vector<int>(heap1, heap1 + size1), vector<int>(heap2, heap2 + size2), size1, size2);

    // Print the merged heap
    for (int i = 0; i < mergedHeap.size(); i++) {
        cout << mergedHeap[i] << " ";
    }
    cout << endl;

    return 0;
}

// } Driver Code Ends

/**
 * For 0 based indexing:
 * 1. leftChildIdx = 2*current + 1
 * 2. rightChildIdx = 2*current + 2
 * 3. parentIdx = (current - 1) / 2
 */