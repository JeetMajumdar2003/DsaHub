#include <bits/stdc++.h>
using namespace std;

// Bubble Sort Function:
// void bubbleSort(vector<int> &v){
//     for (int i = 0; i < v.size()-1; i++){
//         for (int j = 0; j < v.size()-1-i; j++){
//             if (v[j]>v[j+1])
//                 swap(v[j], v[j+1]);
//         }
//     }
//     return;
// }

// Bubble Sort Function (Optimised):
void bubbleSort(vector<int> &v){
    for (int i = 0; i < v.size()-1; i++){
        bool flag = false;
        for (int j = 0; j < v.size()-1-i; j++){
            if (v[j]>v[j+1]){
                flag = true;
                swap(v[j], v[j+1]);
            }
        }
        if(!flag) break;
    }
    return;
}

int main()
{
    int n;
    cin>>n;

    vector<int> v(n);
    // take array elements as input
    for (int i = 0; i < n; i++)
        cin>>v[i];
    
    // Bubble Sort Function:
    bubbleSort(v);

    // Print the sorted array
    for (int i = 0; i < n; i++)
        cout<<v[i]<<" ";


    return 0;
}