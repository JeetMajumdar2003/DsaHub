#include<iostream>
#include<vector>
using namespace std;

bool canPlaceStudent(vector<int> &v, int s, int mid){
    int studentsReq = 1;
    int lastPlaced = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]-lastPlaced >= mid){
            studentsReq++;
            lastPlaced = v[i];
            if (studentsReq == s)
            {
                return true;
            }
            
        }
    }
    return false;
}

int race(vector<int> &v, int s){
    int n = v.size();
    int lo = 1;
    int hi = v[n-1] - v[0];
    int ans = -1;
    while (lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if (canPlaceStudent(v, mid, s))
        {
            ans = mid;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
        
    }
    return ans;
    
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int s;
    cin>>s;
    cout<<race(v,s);
    return 0;
}

/**
 * Time Complexity: O(nlog(v[n-1]-v[0]))
 * Space Complexity: O(1)
 */

