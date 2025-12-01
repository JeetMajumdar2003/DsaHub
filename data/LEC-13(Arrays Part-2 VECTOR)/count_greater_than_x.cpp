#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, count = 0;
    vector<int> v{1,2,3,2,5,4,9,3,2,6,4};
    cout<<"Enter a element: ";
    cin>>x;
    for (int ele:v){
        if (ele > x)
            count++;
    }
    cout<<"No. of elements strictly greater than "<< x <<" is: "<<count;
    return 0;
}