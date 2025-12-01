#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Binary Search for finding target element in a rotated sorted array:
int targetSearch(vector<int> &v, int size, int target){
    int lo = 0;
    int hi = size-1;

    // for Sorted Rotated array:
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
    
        // Terminating Condition:
        if(v[mid]==target) return mid;
        else if(v[lo] <= v[mid]){   // Left Half is Sorted
            if (target>=v[lo] && target<=v[mid])    // Target is in Left Half
                hi = mid-1;
            else                                    // Target is in Right Half
                lo = mid+1;    
        }
        else if(v[lo] >= v[mid]){   // Right Half is Sorted
            if (target>=v[mid] && target<=v[hi])    // Target is in Right Half
                lo = mid+1; 
            else                                    // Target is in Left Half
                hi = mid-1;  
        }
    }
    return -1;
}

// LeetCode-81: Search in Rotated Sorted Array
// Completly resolved the issue of duplicates in the array
int searchInRotatedArray(vector<int>& nums, int size, int target) {
        int l = 0;
        int h = size-1;
        while(l<=h){
            int mid = l + (h-l)/2;

            // Skip duplicates
            while (l < mid && nums[l] == nums[mid]) l++;    // skit left duplicates
            while (h > mid && nums[h] == nums[mid]) h--;    // skit right duplicates

            if(nums[mid] == target) return mid;
            else if(nums[mid] <= nums[h]){
                if(target >= nums[mid] && target <= nums[h])
                    l = mid + 1;
                else 
                    h = mid - 1;
            }
            else if(nums[mid] >= nums[l]){
                if(target >= nums[l] && target <= nums[mid])
                    h = mid - 1;
                else 
                    l = mid + 1;
            }
             else {
                h--;
            }
        }
        return -1;
    }

/**
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
*/

void runTest(vector<int> &v, int target, int expected) {
    // int result = targetSearch(v, v.size(), target);      // Not working properly for duplicates
    int result = searchInRotatedArray(v, v.size(), target);
    // cout << "Array: ";
    // for (int num : v) cout << num << " ";
    // cout << "\nTarget: " << target << "\nResult: " << result << "\nExpected: " << expected << "\n";
    if (result == expected) {
        cout << "Test Passed!\n";
    } else {
        cout << "Test Failed!\n";
    }
}

int main(){
    // Test cases
    vector<int> v1 = {1, 0, 1, 1, 1};
    runTest(v1, 0, 1); // Expected output: 1

    vector<int> v2 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    runTest(v2, 2, 13); // Expected output: 13

    vector<int> v3 = {4, 5, 6, 7, 0, 1, 2};
    runTest(v3, 0, 4); // Expected output: 4

    vector<int> v4 = {4, 5, 6, 7, 0, 1, 2};
    runTest(v4, 3, -1); // Expected output: -1

    vector<int> v5 = {1};
    runTest(v5, 1, 0); // Expected output: 0

    vector<int> v6 = {1};
    runTest(v6, 0, -1); // Expected output: -1

    vector<int> v7 = {};
    runTest(v7, 1, -1); // Expected output: -1

    vector<int> v8 = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    runTest(v8, 2, 13); // Expected output: 13

    vector<int> v9 = {1,0,1,1,1};
    runTest(v9, 0, 1); // Expected output: 1

    return 0;
}