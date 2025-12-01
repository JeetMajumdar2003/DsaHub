#include <iostream>
#include <queue>
using namespace std;

// Function to find kth largest element using min heap
int kThLargestElement(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;  // min heap
    // pushing array sequentially one by one, and if size of heap is greater than k, then pop the top element
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) {
            pq.pop();   // remove n-k smallest elements
        }
    }
    // now we have k largest elements in min heap, so top element will be kth largest element
    return pq.top();
}

int main()
{
	int arr[6] = { 7, 2, 4, 8, 6, 9 };
    int k = 3;

    // M-1: Using Max Heap  // Time: O(nlogn), Space: O(n)
	// defining priority queue
	priority_queue<int> pq; // max heap

	// pushing array sequentially one by one
	for (int i = 0; i < 6; i++) {
		pq.push(arr[i]);
	}
    while (!pq.empty()) {
        if(k == 1) {
            cout << "Kth largest element: " << pq.top() << endl;
            break;
        }
        k--;
        pq.pop();
    }

    // M-2: Using Min Heap  // Time: O(nlogk), Space: O(k)
    k = 3;
    cout<<"Using Min Heap: ";
    cout<<kThLargestElement(arr, 6, k)<<endl;

	return 0;
}
