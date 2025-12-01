#include <bits/stdc++.h>
using namespace std;


// Using Binary Search
/**
 * Time Complexity: O(logN)
 * Space Complexity: O(1)
*/
vector<int> binarySearch(vector<int> &v, int low, int high,  int x){
    // first Occurrence:
    int firstOccurrence=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]==x){
            firstOccurrence =  mid;
            high = mid - 1;
        }
        else if(v[mid]>x) high = mid-1;
        else low = mid+1;
    }

    // Last Occurrence:
    low=0;
    high = v.size()-1;
    int lastOccurrence=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]==x){
            lastOccurrence =  mid;
            low = mid + 1;
        }
        else if(v[mid]>x) high = mid-1;
        else low = mid+1;
    }

    // return ans array:
    vector<int> ans;
    ans.push_back(firstOccurrence);
    ans.push_back(lastOccurrence);
    return ans;
}

int main()
{
    vector<int> v = {2, 5, 5, 5, 5, 6, 8, 9, 9, 9};
    int n = 10;
    int x = 5;
    int low = 0;
    int high = n-1;

    vector<int> result = binarySearch(v, low, high,  x);
    for(int i:result)
        cout<<i<<" ";

    return 0;
}