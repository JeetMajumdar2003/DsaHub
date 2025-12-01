#include <bits/stdc++.h>
using namespace std;

// Insertion Sort Algorithm:    more Optimized
void insertionSort(vector<int> &v){
    for (int i = 1; i < v.size(); i++){
        int current = v[i];

        // find the correct position for our current element
        int j = i-1;
        while (j>=0 && v[j]>current){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = current;
    }
}

void insertion_sort(vector<int> &arr, int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            // int temp = arr[j - 1];
            // arr[j - 1] = arr[j];
            // arr[j] = temp;
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

// Recursive Insertion Sort
void insertionSortRecursive(vector<int> &v, int i, int n){

    // Method 1
    // Traverse the array from 0 to n-1

    // Base Case
    if (i >= n)
        return;

    int current = v[i];

    // find the correct position for our current element
    // Self Work
    int j = i-1;
    while (j>=0 && v[j]>current){
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = current;

    // Assumption: i+1 to n is sorted
    insertionSortRecursive(v, i+1, n);

    // Method 2
    // if (n <= 1)
    //     return;
    // insertionSortRecursive(v, i, n-1);

    // int last = v[n-1];
    // int j = n-2;

    // while (j>=0 && v[j]>last){
    //     v[j+1] = v[j];
    //     j--;
    // }
    // v[j+1] = last;

}

int main()
{
    int n;
    cin>>n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin>>v[i];
    
    // insertionSort(v);
    // insertion_sort(v, n);
    insertionSortRecursive(v, 0, n);

    for (int i = 0; i < n; i++)
        cout<<v[i]<<" ";
    return 0;
}

/**
 * 5
 * 5 1 4 2 8
 */