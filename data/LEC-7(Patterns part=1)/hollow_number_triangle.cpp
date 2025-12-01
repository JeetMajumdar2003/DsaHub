/*
1
22
3 3
4  4
5   5
666666
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of Rows: ";
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++){
            if (i==1 || i==n || j==1 || j==i)
                cout<<i;
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}