#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int maxActivities(vector<pair<int, int>> v) {
    sort(v.begin(), v.end(), compare);
    int res = 1;
    int prev = 0;
    for(int curr = 1; curr < v.size(); curr++) {
        if(v[curr].first > v[prev].second) {
            res++;
            prev = curr;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for(int i = 0; i < n; i++) {
        cin >> start[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> end[i];
    }

    // Convert the input into a vector of pairs
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({start[i], end[i]});
    }

    cout << maxActivities(v) << endl;
    return 0;
}