#include<iostream>
#include<vector>
using namespace std;

int BinarySearchIn2D(vector<vector<int>> &v, int target){
    int n = v.size();   // no of rows
    int m = v[0].size();   // no of columns
    int lo = 0;
    int hi = n*m-1;
    
    while (lo<=hi){
        int mid = lo + (hi-lo)/2;

        // co-ordinates of mid element:
        int x = mid/m;
        int y = mid%m;
        if (v[x][y]==target)
            return true;
        else if (v[x][y]>target)
            hi = mid-1;
        else if(v[x][y]<target)
            lo = mid+1;
        
    }
    return false;
}

int main(){
    vector<vector<int>> v = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int target = 11;
    cout<<BinarySearchIn2D(v, target);
    
    return 0;
}