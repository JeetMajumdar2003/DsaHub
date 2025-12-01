#include <bits/stdc++.h>
using namespace std;

// Using Insertion sort
void insertionSort(vector<int> &v, int n){
    for (int i = 0; i < n; i++){
        if (v[i]==0){
            int zero=v[i];
            int j;
            for (j = i+1; j < n; j++){
                v[j-1]=v[j];
            }
            v[j-1]=zero;
        }
    }
}

// Using Bubble Sort:
// void bubbleSort(vector<int> &v, int n){
//     for (int i = 0; i < n-1; i++){
//         if (v[i]==0){
//             for (int j = i; j < n-1; j++){
//                 swap(v[j], v[j+1]);
//             }
//         }
//     }
// }

// bubble sort by ma'am:
void bubbleSort(vector<int> &v, int n){
    for (int i = n-1; i >= 0; i--){
        int j=0;
        bool flag=false;
        while (j!=i){
            if(v[j]==0 && v[j+1]!=0){
                swap(v[j], v[j+1]);
                flag=true;
            }
            j++;
        }
        if(!flag) break;
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    // Sorting algorithm:
    insertionSort(arr, n);
    // bubbleSort(arr, n);


    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}