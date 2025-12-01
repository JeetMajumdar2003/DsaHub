#include<iostream>
#include<vector>
using namespace std;

// Can Distribute Chocolate function:
bool canDsitribute(vector<int> &v, int mid, int s){
    int n = v.size();
    int studentsReq = 1;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i]>mid)
        {
            return false;
        }
        if (currentSum+v[i]>mid)
        {
            studentsReq++;
            currentSum = v[i];
            if(studentsReq>s) return false;
        }
        else
        {
            currentSum += v[i];
        }
    }
    return true;
}

// Distribute Chocolate function:
int distributeChocolate(vector<int> &v, int s){
    int n = v.size();
    int lo = v[0]; // for sorted boxes otherwise sort the boxes:
    int hi = 0;
    for (int i = 0; i < n; i++)
    {
        hi += v[i];
    }
    int ans = -1;
    while (lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(canDsitribute(v, mid, s)){
            ans = mid;
            hi = mid -1;
        }
        else {
            lo = mid +1;
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
    cout<<distributeChocolate(v,s);
    return 0;
}



