#include <bits/stdc++.h>
using namespace std;


// Using Binary Search
/**
 * Time Complexity: O(logN)
 * Space Complexity: O(1)
*/
int lowerBound(vector<int> &v, int low, int high,  int x){
    // first Occurrence:
    int firstOccurrence=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]>=x){  // lowerBound(>=): it will give the first occurrence
            firstOccurrence =  mid;
            high = mid - 1; // discard right
        }
        else low = mid+1;
    }
    return firstOccurrence;
}

int upperBound(vector<int> &v, int low, int high,  int x){
    // Last Occurrence:
    int lastOccurrence=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]>x){   // upperBound(>): it will give the next index of the last occurrence so to get last occurrence we minus 1 from the upperBound
            lastOccurrence =  mid;
            high = mid - 1; // discard right
        }
        else low = mid+1;
    }
    return lastOccurrence;
}

int main()
{
    vector<int> v = {2, 5, 5, 5, 5, 6, 8, 9, 9, 9};
    int n = 10;
    int x = 5;
    int low = 0;
    int high = n-1;

    vector<int> result;
    int lb = lowerBound(v, low, high, x);
    if(v[lb]!=x){
        result.push_back(-1);
        result.push_back(-1);
    }
    else{
        int ub = upperBound(v, low, high,x);
        result.push_back(lb);
        result.push_back(ub-1);
    }
    cout<<result[0]<<" "<<result[1];

    return 0;
}