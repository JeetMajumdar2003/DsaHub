#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of Rows: ";
    cin>>n;

    // Methode-1:
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <= 2*i-1; k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
    // Methode-2: Using Extra variable.
    int nsp = n-1; // no. of spaces
    int nst = 1;    // no. of stars
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= nsp; j++)
            cout<<" ";
        for (int k = 1; k <= nst; k++)
            cout<<"*";
        nsp--;
        nst += 2;
        cout<<endl;
    }

    //Method-3:
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <= 2*i-1; k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}