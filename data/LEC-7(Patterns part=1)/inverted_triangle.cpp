#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of Rows: ";
    cin>>n;
    // M-1:
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i+j <= n+1; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
    // M-2:
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}