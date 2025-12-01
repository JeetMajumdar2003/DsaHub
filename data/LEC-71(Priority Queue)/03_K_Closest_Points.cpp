#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find k closest points to origin(0, 0):
vector<pair<int, int>> kClosestPoints(vector<pair<int, int>> points, int n, int k) {
    priority_queue<pair<int, int>> pq;  // max heap(distance, index)
    for(int i = 0; i < n; i++) {
        int dist = points[i].first + points[i].second;  // Manhattan distance
        pq.push({dist, i});
        if(pq.size() > k) {
            pq.pop();
        }
    }
    vector<pair<int, int>> ansPoints(k);
    while(!pq.empty()) {
        ansPoints[--k] = points[pq.top().second];
        pq.pop();
    }
    return ansPoints;
}

int main()
{
    // M-1:
	// int n = 6, k = 3;
    // int arr[6][2] = { { 5, 3 }, { 1, 2 }, { 3, 4 }, { 7, 8 }, { 5, 6 }, { 9, 10 } };
    // priority_queue<pair<int, int>> pq;  // max heap
    // for(int i = 0; i < n; i++) {
    //     int dist = arr[i][0] + arr[i][1];   // Manhattan distance
    //     pq.push({dist, i});
    //     if(pq.size() > k) {
    //         pq.pop();
    //     }
    // }
    // while(!pq.empty()) {
    //     cout << arr[pq.top().second][0] << " " << arr[pq.top().second][1] << endl;
    //     pq.pop();
    // }

    // M-2:
    int n = 6, k = 3;
    vector<pair<int, int>> points = { { 5, 3 }, { 1, 2 }, { 3, 4 }, { 7, 8 }, { 5, 6 }, { 9, 10 } };

    vector<pair<int, int>> ansPoints = kClosestPoints(points, n, k);

    for(auto point: ansPoints) {
        cout << point.first << " " << point.second << endl;
    }

	return 0;
}

/**
 * Manhattan distance: |x1-x2| + |y1-y2|
 * Euclidean distance: sqrt((x1-x2)^2 + (y1-y2)^2)
 */