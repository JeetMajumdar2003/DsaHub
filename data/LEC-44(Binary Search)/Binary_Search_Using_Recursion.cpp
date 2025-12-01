#include <iostream>
#include<vector>
using namespace std;

// Binary Search Algorithm:(Recursive Implementation)
int binarySearchRecursive(vector<int> &v, int lo, int hi, int target){

    // Base Case:
    if(lo>hi) return -1;

// Self Work:
    // calculate the mid point for the search space:
    // int mid = (hi+lo)/2;
    // Modify the mid index calculation to tackel Overflow:
    int mid = lo + (hi-lo)/2;

    // Self Work:
    if(v[mid]==target) return mid;
    else if(v[mid]<target){
        // call for right sub array
        return binarySearchRecursive(v, mid+1, hi, target);
    }
    else {
        // call for left sub array
        return binarySearchRecursive(v, lo, mid-1, target);
    }
    

}

int main()
{
    // Input Veactor:
    vector<int> v = {2, 4, 5, 7, 15, 24, 45, 50};
    int target = 15;    // target element
    int lo = 0;
    int hi = v.size()-1;
    cout<< "Target Element present at Index: " << binarySearchRecursive(v, lo, hi, target);
    return 0;
}

/**
 * Time Complexity: O(logN)
 * Space Complexity: O(logN)
*/
