#include<iostream>
#include<vector>
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
        else if(v[lo] <= v[mid]){
            if (target>=v[lo] && target<=v[mid])
                hi = mid-1;
            else
                lo = mid+1;    
        }
        else if(v[lo] >= v[mid]){
            if (target>=v[mid] && target<=v[hi])
                lo = mid+1; 
            else
                hi = mid-1;  
        }
    }
    return -1;
}
/**
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
*/


int main(){
    int n;
    int target;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    cin>>target;
    cout<<targetSearch(v, n, target);
    
    return 0;
}