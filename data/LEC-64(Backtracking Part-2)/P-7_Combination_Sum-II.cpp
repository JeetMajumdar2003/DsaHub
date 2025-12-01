#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Global result 2D vector
vector<vector<int>> result;

void combinationSum2(vector<int>& arr, int idx, int target, vector<int>& v){
    // Base Case
    if (target == 0){
        result.push_back(v);
        return;
    }
    if (idx == arr.size() or target < 0) return;

    // Recursive Cases
    // Include the current element
    if(arr[idx]<=target){
        v.push_back(arr[idx]);
        combinationSum2(arr, idx+1, target-arr[idx], v);
        v.pop_back();
    }

    // Skip the repeated elements
    while (idx+1 < arr.size() and arr[idx] == arr[idx+1]) idx++;

    // Exclude the current element
    combinationSum2(arr, idx+1, target, v);

    return;
}

// Print 2d vector
void print2DVector(vector<vector<int>>& v){
    cout << "[";
    for (int i=0; i<v.size(); i++){
        cout << "[";
        for (int j=0; j<v[i].size(); j++){
            cout << v[i][j];
            if (j != v[i].size()-1) cout << ", ";
        }
        cout << "]";
        if (i != v.size()-1) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<int> arr = {2, 5, 2, 1, 2}; 
    sort(arr.begin(), arr.end());
    int target = 6;
    vector<int> v;
    combinationSum2(arr, 0, target, v);
    print2DVector(result);
    return 0;
}