#include <bits/stdc++.h>
using namespace std;

int main()
{
    // (1) Using Array:
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    // k can be greater than n
    k = k % n;
    
    // Inserting (M-1)
    int temp[n];
    // insert first k element
    for (int i = 0; i < k; i++){
        temp[i] = arr[n-k+i];
    }
    // insert remaning n-k ekements
    for (int i = k; i < n; i++){
        temp[i] = arr[i-k];
    }
    // print new array
    for (int i = 0; i < n; i++){
        cout << temp[i]<<" ";
    }
    cout<<endl;

    // M-2
    int ansarray[n], j=0;
    cout<<"Enter the value of k: ";
    cin>>k;
    k = k % n;
    // insert 
    for (int i = n-k; i < n; i++){
        ansarray[j++]=arr[i];
    }
    // insert remaning n-k ekements
    for (int i = 0; i < n-k; i++)
    {
        ansarray[j++]=arr[i];
    }
    // print new array
    for (int i = 0; i < n; i++){
        cout << ansarray[i]<<" ";
    }
    cout<<endl;

    // (2) Using Vector:
    vector <int> v = {1,2,3,4,5};
    cout<<"Enter the value of k: ";
    cin>>k;
    for (int i = 0; i < k; i++){
        v.insert(v.begin(), v[v.size()-1]);
        v.pop_back();
        // v.resize(v.size());
    }
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;

    // (3) Using vector Reverse Operation: reverse(start(inclusive), end(exclusive)
    vector <int> v1 = {1,2,3,4,5};
    cout<<"Enter the value of k: ";
    cin>>k;
    k = k % v.size();
    reverse(v1.begin(), v1.end());
    reverse(v1.begin(), v1.begin()+k);
    reverse(v1.begin()+k, v1.end());
    for (int i = 0; i < v1.size(); i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    return 0;
}