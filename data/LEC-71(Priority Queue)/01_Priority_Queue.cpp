// C++ program to demonstrate the use of priority_queue
#include <iostream>
#include <queue>
using namespace std;

// driver code
int main()
{
	int arr[6] = { 7, 2, 4, 8, 6, 9 };

	// defining priority queue
	priority_queue<int> pqMax; // max heap
    priority_queue<int, vector<int>, greater<int>> pqMin; // min heap

	// printing array
	cout << "Array: ";
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << endl;
	// pushing array sequentially one by one
	for (int i = 0; i < 6; i++) {
		pqMax.push(arr[i]);
        pqMin.push(arr[i]);
	}

	// printing priority queue
	cout << "Priority Queue(Max Heap): ";
	while (!pqMax.empty()) {
		cout << pqMax.top() << ' ';
		pqMax.pop();
	}
    cout << endl;

    cout << "Priority Queue(Min Heap): ";
    while (!pqMin.empty()) {
        cout << pqMin.top() << ' ';
        pqMin.pop();
    }

	return 0;
}
