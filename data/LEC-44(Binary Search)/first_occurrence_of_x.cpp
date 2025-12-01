#include <bits/stdc++.h>
using namespace std;

// Using Linear Search(Brute Force Solution):
/**
 * Time Complexity: O(N)
 * Space Complexity: O(1)
*/

int linearSearch(vector<int> &v, int n, int x){
    for (int i = 0; i < n; i++){
        if(v[i]==x) return i;
    }
    return -1;
}

// Using Binary Search
/**
 * Time Complexity: O(logN)
 * Space Complexity: O(1)
*/
int binarySearch(vector<int> &v, int low, int high,  int x){
    int firstOccurrence=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]==x){
            firstOccurrence =  mid;
            high = mid - 1; // search in the left subarray, is there any other occurrence of x present or not.
        }
        else if(v[mid]>x) high = mid-1;
        else low = mid+1;
    }
    return firstOccurrence;
}

int main()
{
    vector<int> v = {2, 5, 5, 5, 5, 6, 8, 9, 9, 9};
    int n = 10;
    int x = 5;
    int low = 0;
    int high = n-1;

    cout<<linearSearch(v, n, x)<<endl;
    cout<<binarySearch(v, low, high,  x)<<endl;
    return 0;
}