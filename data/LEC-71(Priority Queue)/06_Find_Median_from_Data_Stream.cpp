// Given a stream of integers, we need to find the median of the stream at any point in time.
/** Approach:
1. We can use two priority queues to store the elements of the stream.
2. The first priority queue will store the first half of the stream in decreasing order.
3. The second priority queue will store the second half of the stream in increasing order.
4. The median will be the top element of the first priority queue.
5. If the size of the first priority queue is greater than the second priority queue, then the median will be the top element of the first priority queue.
6. If the size of the second priority queue is greater than the first priority queue, then the median will be the top element of the second priority queue.
7. If the size of both priority queues is equal, then the median will be the average of the top elements of both priority queues.
8. We will maintain the size of the first priority queue to be greater than or equal to the second priority queue.
9. If the size of the first priority queue is greater than the second priority queue, then we will push the element into the first priority queue.
10. If the size of the second priority queue is greater than the first priority queue, then we will push the element into the second priority queue.
11. If the size of both priority queues is equal, then we will push the element into the first priority queue.
12. We will balance the size of both priority queues by transferring the top element of the first priority queue to the second priority queue.
13. We will calculate the median based on the size of both priority queues.
14. The time complexity of this approach is O(log n) for each element.
15. The space complexity of this approach is O(n) where n is the number of elements in the stream.
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap; // Max-heap for the lower half of the numbers
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for the upper half of the numbers

    // Adds a number into the data structure.
    void addNum(int num) {
        // Add to maxHeap if it's empty or the number is less than or equal to the top of maxHeap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            // Otherwise, add to minHeap
            minHeap.push(num);
        }

        // Balance the heaps if necessary
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            // If both heaps are of equal size, the median is the average of the two middle elements
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            // If maxHeap has more elements, the median is the top of maxHeap
            return maxHeap.top();
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    cout << "Median: " << mf.findMedian() << endl; // Output: Median: 1
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: Median: 2
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: Median: 2
    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl; // Output: Median: 2.5
    mf.addNum(5);
    cout << "Median: " << mf.findMedian() << endl; // Output: Median: 3
    mf.addNum(8);
    cout << "Median: " << mf.findMedian() << endl; // Output: Median: 3.5
    return 0;
}