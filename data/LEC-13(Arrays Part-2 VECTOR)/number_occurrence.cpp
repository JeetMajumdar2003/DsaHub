#include <bits/stdc++.h>
using namespace std;

int main()
{
    int key, count = 0;
    vector<int> v{1,2,3,2,1,3,4,1,2,1,3,2,2};
    cout<<"Enter a element: ";
    cin>>key;
    for (int i = 0; i < v.size(); i++){
        if (v[i]==key)
            count++;
    }
    cout<<"No. of occurrence of "<<key<<" is: "<<count;
    return 0;
}