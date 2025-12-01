#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Global result 2D vector
vector<vector<int>> result;

// Combination Sum-I: We can use an element of the array as many times as needed.
void combinationSum(vector<int>& arr, int idx, int target, vector<int>& v){
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
        combinationSum(arr, idx, target-arr[idx], v);
        v.pop_back();
    }

    // Exclude the current element
    combinationSum(arr, idx+1, target, v);

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
    vector<int> arr = {2, 3, 4};
    int target = 6;
    vector<int> v;
    combinationSum(arr, 0, target, v);
    print2DVector(result);
    return 0;
}