#include <iostream>
#include<vector>
using namespace std;

// Binary Search Algorithm:
int binarySearch(vector<int> &v, int target){
    // Define Search Space:
    int lo = 0; // start of the search space
    int hi = v.size()-1;    // end of the search space

    while(lo <= hi){
        // calculate the mid point for the search space:
        // int mid = (hi+lo)/2;
        // Modify the mid index calculation  to tackel Overflow:
        int mid = lo + (hi-lo)/2;

        if(v[mid]==target) return mid;
        else if(v[mid]<target){
            // discard the left subarray along with mid element;
            lo = mid + 1;
        }
        else {
            // discard the right subarray along with mid element
            hi = mid - 1;
        }
    }
    return -1;

}

int main()
{
    // Input Veactor:
    vector<int> v = {2, 4, 5, 7, 15, 24, 45, 50};
    int target = 15;    // target element
    cout<< "Target Element present at Index: " << binarySearch(v, target);
    return 0;
}

/**
 * Time Complexity: O(logN)
 * Space Complexity: O(1)
*/
