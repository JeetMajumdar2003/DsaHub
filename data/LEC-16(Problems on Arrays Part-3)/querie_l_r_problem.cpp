#include <bits/stdc++.h>
using namespace std;

// index -> 0  1  2  3  4  5  6
// vector->    x1 x2 x3

// 0 based indexing -> 0 .... n-1
// 1 based indexing -> 1 .... n

// Output:
// Enter Vector Size: 5
// vector v(n+1) = {0, 5, 1, 2, 3, 4}
// prefix sum array pv -> 0, 5, 6, 8, 11, 15
// l = 2, r = 4
// ans = pv[r] - pv[l-1] = pv[4] - pv[1] = 11-5 = 6

int main()
{
    int n;
    cout<<"Enter Vector Size: ";
    cin>>n;

    // 1 based Indexing:
    vector<int> v(n+1, 0);
    for (int i = 1; i < n+1; i++){ // 1--->n
        cin>>v[i];
    }
    
    // calculate prefix sum array:
    for (int  i = 1; i < n+1; i++){ // 1--->n
        v[i]+=v[i-1];
        // cout<<v[i]<<" ";
    }

    // Input queries:
    int q;
    cout<<"Enter Queries: ";
    cin>>q;

    while (q--)
    {
        int l,r;
        cout<<"Enter l and r: ";
        cin>>l>>r;

        int ans = 0;
        // ans = prefixSumArray[r] - prefixSumarray[l-1]:
        ans = v[r] - v[l-1];
        cout<<ans<<endl;
    }
    
    // Now calculate in 0 based Indexing:
    vector<int> v1(n);
    for (int i = 0; i < n; i++){
        cin>>v1[i];
    }   // {5,4,2,1,3}

    // calculate prefix sum array:
    for (int  i = 0; i <= n-1; i++){
        v1[i] += v1[i-1];
    }   // {5,9,11,12,15}

    // Input queries:
    int q1;
    cout<<"Enter Queries: ";
    cin>>q1;

    while (q1--)
    {
        int l,r;
        cout<<"Enter l and r: ";
        cin>>l>>r;
        int ans = v1[r-1] - v1[l-2];
        cout<<ans<<endl;
    }
    
    return 0;
}