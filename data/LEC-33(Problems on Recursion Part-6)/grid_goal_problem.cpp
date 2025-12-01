#include <iostream>
using namespace std;

int countPath(int i, int j, int m, int n){
    // base case
    // if(i>=m || j>=n) return 0;  // also (i==m || j==n)
    // if((i==m-1 && j==n-1)) return 1;    // also (i==m-1 || j==n-1)

    // base case
    // if we use or operator in place of and then we don't need to use the 1st if statement
    if((i==m-1 || j==n-1)) return 1;

    // or
    // if((i==m-1 && j==n-1) || (i==m-1 && j==n-2)) return 1;

    // self work
    return (countPath(i+1, j, m, n) + countPath(i, j+1, m, n));
}

int main(){
    int result = countPath(0,0,4,3);
    cout<<result;
    return 0;
}