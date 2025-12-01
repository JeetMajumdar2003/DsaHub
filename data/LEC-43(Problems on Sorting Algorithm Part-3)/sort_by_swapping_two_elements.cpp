#include <iostream>
using namespace std;

void swapSorting(int arr[], int n){
    int i=0, j=1;
    while(i++<j++){
        if(arr[i]>arr[j]) swap(arr[i++], arr[j]);
    }
}

int main()
{
    int arr[] = {2, 3, 4, 6, 5, 8, 9};
    int n = 7;

    swapSorting(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}