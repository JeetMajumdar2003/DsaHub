#include <iostream>
using namespace std;

int power(int p, int q){
    if(q==1) return p;

    // return p*power(p, q-1);
    int result = power(p, q/2);
    return q%2==0 ? result*=result : result*=result*p;
}

int main() {
    int p, q;
    cin>>p>>q;
    int ans = power(p, q);
    cout<<ans;
    return 0;
}