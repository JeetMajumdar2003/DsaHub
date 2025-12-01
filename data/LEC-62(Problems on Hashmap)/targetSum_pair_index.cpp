#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the pair of indices whose sum is equal to the target sum
vector<int> targetSum(vector<int> &arr, int target) {
    vector<int> result;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (mp.count(complement)) {
            result.push_back(mp[complement]);
            result.push_back(i);
            return result;
        }
        mp[arr[i]] = i;
    }
    return result;
}

int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> result = targetSum(arr, target);
    if (result.size() == 0) {
        cout << "No pair found with the given target sum" << endl;
    } else {
        cout << "The pair of indices whose sum is equal to the target sum is: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}