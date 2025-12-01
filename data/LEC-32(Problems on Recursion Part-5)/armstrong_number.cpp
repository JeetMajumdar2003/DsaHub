#include <bits/stdc++.h>
using namespace std;

// power function
int pow_recursive(int num, int p){
    if(p==1) return num;
    int power = pow_recursive(num, p/2);
    if(p%2==0) return power*power;
    else return num * power*power;
}

int armstrongNum(int n, int d){
    if(n>=0 && n<=9) return n;  // or if(n==0) return 0;
    int result = pow_recursive(n%10,d) + armstrongNum(n/10, d);
    return result;
}

int main()
{
    int num = 1634;
    int digit = 4;
    int result = armstrongNum(num, digit);
    if(result==num) cout<<"Yes";
    else cout<<"No";
    return 0;
}

/**
 * ex: 153, 1634
 */