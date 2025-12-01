#include <iostream>
using namespace std;

int frogJump(int *arr, int n, int i){
    // base case
    if(i==n-1) return 0;    // last stair
    if(i==n-2) return frogJump(arr, n, i+1) + abs(arr[i]-arr[i+1]);   // second last stair -> frogJump(arr, n, i+1)=0

    // recursive case
    int result = min(frogJump(arr, n, i+1) + abs(arr[i]-arr[i+1]), frogJump(arr, n, i+2) + abs(arr[i]-arr[i+2]));
    return result;
}

int main()
{
    int arr[]={1,3,5,6,8,12,17};    //{10,30,40,20}
    int n= 7;
    cout<<frogJump(arr, n,0);
    return 0;
}

// my solution: (wrong)
// #include <iostream>
// using namespace std;
// int frogJump(int *arr, int n){
//     int a;
//     int *result=&a;
//     if(n==0) return 0;
//     if(n==1) return abs(arr[1]-arr[0]);
//     if(n==2) return min(abs(arr[2]-arr[0]), abs(arr[2]-arr[1]));
//     if(abs(arr[n-1]-arr[n-2]+frogJump(arr, n-1))<abs(arr[n-1]-arr[n-3]+frogJump(arr, n-2))){
//         *result = abs(arr[n-1]-arr[n-2]) + frogJump(arr, n-1);
//     }
//     else{
//         *result = abs(arr[n-1]-arr[n-3]) + frogJump(arr, n-2);
//     }
//     return *result;
// }
// int main()
// {
//     int arr[]={1,3,5,6,8,12,17};
//     cout<<frogJump(arr, 7);
//     return 0;
// }