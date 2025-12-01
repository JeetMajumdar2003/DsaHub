#include <bits/stdc++.h>
using namespace std;

// Sum in range function
int sumInRange(int x, int y){
    int sum = 0;
    for (int i = x; i <= y; i++){
        sum += i;
    }
    return sum;
}

// Sum in range function(Optimised):
int sumInRangeOptimised(int x, int y){
    int sum = 0;
    int n = y - x + 1;
    int a = x, d=1;
    sum = (n * (2*a + (n - 1)*d)) / 2;
    return sum;
}

int main(){   
    cout<<sumInRange(2, 100000)<<endl;
    cout<<sumInRangeOptimised(2, 100000)<<endl;
    return 0;
}