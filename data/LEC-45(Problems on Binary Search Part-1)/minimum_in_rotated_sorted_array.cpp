#include<iostream>
#include<vector>
using namespace std;

// Binary Search for finding minimum element in a rotated sorted array:
int minNumber(vector<int> &v, int size){
    int start = 0;
    int last = size-1;
    // Array only have one element:
    if(size==1) return 0;
    // Array is sorted:
    if(v[start]<v[last]) return 0;

    // for Sorted Rotated array:
    while(start<=last){
        int mid = start + (last-start)/2;

        // Terminating Condition:
        if(v[mid]>v[mid+1]) return mid+1;
        else if(v[mid]<v[mid-1]) return mid;

        // Left and Right subarray call condition:
        if (v[start]>v[mid]) // middle element is not rotated -> Left subarray call
            last = mid-1;
        else if(v[start]<v[mid]) // middle element is rotated -> Right subarray call
            start = mid+1;
    }
    return -1;
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
    cout<<"Index of Minimum Element: "<<minNumber(v, n);
    
    return 0;
}