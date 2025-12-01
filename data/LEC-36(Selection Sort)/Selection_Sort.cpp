#include <bits/stdc++.h>
using namespace std;

// Selection Sort Algorithm:
void selectionSort(vector<int> &v){
    for (int i = 0; i < v.size()-1; i++){
        int minIdx = i;
        for (int j = i+1; j < v.size(); j++){
            if(v[j]<v[minIdx])
                minIdx=j;
        }
        if(minIdx!=i)
            swap(v[i], v[minIdx]);
    }
    return;
}

int main()
{
    int n;
    cin>>n;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }

    selectionSort(v);

    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}