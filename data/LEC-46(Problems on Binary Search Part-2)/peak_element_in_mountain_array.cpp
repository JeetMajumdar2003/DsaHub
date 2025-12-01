#include<iostream>
#include<vector>
using namespace std;

// Binary Search for finding minimum element in a rotated sorted array:
int peakInMountainArray(vector<int> &v, int size){
    int lo = 0;
    int hi = size-1;

    // // for Sorted Rotated array: My Method
    // while(lo<=hi){
    //     int mid = lo + (hi-lo)/2;
    //     // Terminating Condition:
    //     if(v[mid]>v[mid-1] && v[mid]>v[mid+1]) 
    //         return mid;
    //     else if(v[mid]<v[mid+1])    // discard left subarray and search in right subarray
    //         lo = mid+1;
    //     else if(v[mid]<v[mid-1])    // discard right subarray and search in left subarray
    //         hi = mid-1;
    // }
    // return -1;

    int ans=-1;
    // Sir Method:
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        // Terminating Condition:
        if(v[mid]>v[mid-1]){    // discard left subarray
            ans = max(ans, mid);    // store the maximum index
            lo = mid+1;     // search in right subarray
        }
        else
            hi = mid-1;
    }
    return ans;
}
/**
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
*/


int main(){
    int n;
    cin>>n; 
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    cout<<peakInMountainArray(v, n);
    
    return 0;
}

/**
 * Test Cases:
 * v = [1, 3, 4, 5, 2, 1]
 * Output Index: 3 (5 is the peak element)
 */