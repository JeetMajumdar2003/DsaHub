#include<iostream>
using namespace std;

int digit_sum(int n){
    if(n>=0 && n<=9){
        return n;
    }
    return n%10 + digit_sum(n/10);
}

int main() {
    int n;
    cin>>n;
    int sum = digit_sum(n);
    cout<<sum;
    return 0;
}