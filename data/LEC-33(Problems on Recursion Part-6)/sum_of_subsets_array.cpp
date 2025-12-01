#include <bits/stdc++.h>
using namespace std;

void sumOfSubsets(int *arr, int n,int i, int sum,  vector<int> &result){
    // base case
    if(i==n){
        result.push_back(sum);
        return;
    }

    sumOfSubsets(arr, n, i+1, sum+arr[i], result);  // pick the i'th  element
    sumOfSubsets(arr, n, i+1, sum, result);  // don't pick the i'th  element
}

int main()
{
    int arr[]= {2,4,5};
    int n=3;
    vector<int> result;
    sumOfSubsets(arr,n,0,0,result);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    
    return 0;
}