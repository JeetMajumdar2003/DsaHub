#include <iostream>
using namespace std;

// int printSum(int n){
//     int sum;
//     // base case
//     if(n==0) {
//         return 0;
//     }
//     if(n%2==1){
//         sum = printSum(n-1) + n;
//     }
//     else if(n%2==0){
//         sum = printSum(n-1) - n;
//     }
//     return sum;
// }

// by sir
int sum(int n){
    // base case
    if(n==0) return 0;
    // self work: assume sum(n-1) correctly calculate sum of n-1 terms with alternate sign, then we will add n if its odd otherwise substract if its even
    int result = sum(n-1) + ((n%2==0)? (-n):n);
    return result;
}

int main()
{
    // cout<<printSum(10);

    // by sir
    cout<<sum(10);
    return 0;
}