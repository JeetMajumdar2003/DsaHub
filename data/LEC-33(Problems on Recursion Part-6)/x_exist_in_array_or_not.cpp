#include <iostream>
using namespace std;

bool targetValue(int *arr, int n, int i, int x){
    // base case
    if(i==n) return 0;

    return (arr[i]==x) || targetValue(arr, n, i+1, x);

    // my logic
    // if(arr[i]==x) return 1;
    // else return targetValue(arr, n, i+1, x);
}

int main()
{
    int arr[] = {4,12,54,14,3,8,6,1};
    int n = 8;
    int x = 14;
    int result = targetValue(arr, n,0,x);
    if(result==1) cout<<"Yes";
    else cout<<"No";
    return 0;
}