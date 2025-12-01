#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,5,6,9,4,6,7};
    const int n = 1e5 +10;
    vector<int> freq(n,0);
    for(int i=0; i<9; i++)
        freq[v[i]] = 1;
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    while(q--){
        int queryElement;
        cout<<"Enter the number to be searched: ";
        cin>>queryElement;
        if(freq[queryElement] == 1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}