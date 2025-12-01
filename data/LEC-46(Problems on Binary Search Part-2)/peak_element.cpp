#include<iostream>
#include<vector>
using namespace std;

int peakElementIdx(vector<int> &v, int n){
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;

        // Edge Cases:
        // if mid is 0th index => only 2 elements in array only check with (mid+1)
        if (mid == 0){
            if (v[mid]>v[mid+1])
                return 0;
            else
                return 1;
            
        }
        else if (mid == n-1){   // if mid is last index => only check with (mid-1)
            if (v[mid]>v[mid-1])
                return n-1;
            else
                return n-2;
            
        }
        else{
            if (v[mid]>v[mid+1] && v[mid]>v[mid-1])
                return mid;
            else if (v[mid]>v[mid-1])
                lo = mid+1;
            else
                hi = mid - 1;
        }
        
    }
    return -1;
}

int findPeakElement(const vector<int> &num) {
    int low = 0;
    int high = num.size()-1;
    
    while(low < high)
    {
        int mid1 = (low+high)/2;
        int mid2 = mid1+1;
        if(num[mid1] < num[mid2])
            low = mid2;
        else
            high = mid1;
    }
    return low;
}

int main(){
    int n;
    cin>>n; 
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    cout<<"Index of the Peak Element: "<<peakElementIdx(v, n)<<endl;
    cout<<"Index of the Peak Element: "<<findPeakElement(v);
    
    return 0;
}