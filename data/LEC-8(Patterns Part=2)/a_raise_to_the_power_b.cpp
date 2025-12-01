#include <iostream>
using namespace std;

int main()
{
    int a, b, ans = 1;
    cout<<"Enter base a: ";
    cin>>a;
    cout<<"Enter power b: ";
    cin>>b;
    for (int i = 1; i <= b; i++)
    {
        ans*=a;
    }
    cout<<a<<" raise to the power "<<b<<" is= "<<ans<<endl;
    return 0;
}