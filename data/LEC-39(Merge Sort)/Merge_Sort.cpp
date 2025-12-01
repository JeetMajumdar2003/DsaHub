#include<iostream>

using namespace std;

// Merge Function for combining sorted subarrays into sorted array:
void merge(int arr[], int l, int mid, int r){
    // size of temp arrays:
    int an = mid - l + 1;
    int bn = r - mid;
    // create 2 temp arrays:
    int a[an];
    int b[bn];

    // fill elements into temp arrays:
    for (int i = 0; i < an; i++){
        a[i] = arr[l+i];
    }
    for (int j = 0; j < bn; j++){
        b[j] = arr[mid+1+j];
    }
    
    // now compare and combine a and b arrays to get final output:
    int i=0;    // initial index of first subarray, a
    int j=0;    // initial index of second subarray, b
    int k=l;    // initial index of merged subarray

    while (i<an && j<bn){
        if(a[i]<b[j]){
            arr[k++] = a[i++];
        }
        else {
            arr[k++] = b[j++];
        }
    }
    while (i<an){
        arr[k++] = a[i++];
    }
    while (i<bn){
        arr[k++] = b[j++];
    }

    // OR
    // while (i<an || j<bn){
    //     if(i<an && (j>=bn || a[i]<b[j])){
    //         arr[k++] = a[i++];
    //     }
    //     else {
    //         arr[k++] = b[j++];
    //     }
    // }
    
}

// Merge Sort Recursive Function:
void mergeSort(int arr[], int l, int r){

    // Base Case:
    if(l>=r){
        return;
    }

    // Recursive Function:
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    // Merge Function:
    merge(arr, l, mid, r);
}

int main(){
    int arr[] = {10, 28, 24, 6, 34, 18, 38, 44};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}