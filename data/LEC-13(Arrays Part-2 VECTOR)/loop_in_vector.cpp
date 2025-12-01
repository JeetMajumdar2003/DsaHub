#include <bits/stdc++.h>
using namespace std;

// Print function:
void print(vector<int> v){
    cout<<"Size: "<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    // Insert elements in vector
    // For loop:
    // Method-1
    vector<int> v;
    for (int i = 0; i < 5; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    // Print using print function:
    print(v);
    // Method-2
    vector<int> v1(5);
    for (int i = 0; i < 5; i++){
        cin>>v1[i];
    }
    // Print using for loop:
    for (int i = 0; i < v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    // for-each loop:
    vector<int> v2(5);
    for(int& ele:v2){
        cin>>ele;
    }
    // Print using for-each loop:
    for(int ele:v2){
        cout<<ele<<" ";
    }
    cout<<endl;

    // While loop:
    vector<int> v3;
    int idx = 0;
    while (idx<5){
        int ele;
        cin>>ele;
        v3.push_back(ele);
        idx++;
    }
    // Print using while loop:
    int i = 0;
    while (i<v3.size()){
        cout<<v3[i]<<" ";
        i++;
    }
    cout<<endl;
    return 0;
}