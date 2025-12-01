#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,2,1,3,4,1,2};
    int key, last_occurrence = -1;
    cout<<"Enter the element for which you want the alst occurrence: ";
    cin>>key;

    // Traverse from the begining:
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]==key)
            last_occurrence = i;
    }
    cout<<"Last Occurrence of "<<key<<" is: "<<last_occurrence<<endl;

    // Traverse from the end:
    for (int i = v.size()-1; i >= 0; i--)
    {
        if (v[i]==key){
            cout<<"Last Occurrence of "<<key<<" is: "<<i;
            break;
        }
    }
    
    return 0;
}