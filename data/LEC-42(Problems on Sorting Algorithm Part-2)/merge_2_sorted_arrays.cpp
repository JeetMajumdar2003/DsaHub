#include <bits/stdc++.h>
using namespace std;


// Merge Two Array Function:
vector<int> mergeArray(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();

    vector<int> v(n+m);

    int i=0, j=0, k=0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            v[k++] = arr1[i++];
        }
        else if(arr1[i]>arr2[j]){
            v[k++] = arr2[j++];
        }
    }
    while(i<n){
        v[k++] = arr1[i++];
    }
    while (j<m){
        v[k++] = arr2[j++];
    }
    return v;
}

int main()
{
    vector<int> arr1 = {5,8,10};
    vector<int> arr2 = {2,7,8};

    vector<int> ans = mergeArray(arr1, arr2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}