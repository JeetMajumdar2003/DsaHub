#include <iostream>
#include <vector>
using namespace std;

// Pivot element position function:
int position(vector<int> &v, int first, int last){
    // Select the Pivot element:
    int pivot = v[last];

    // initialize two indexes(i, j):
    int i = first-1;  // for inserting elements (< pivot)
    int j = first;  // for finding elements (< pivot)

    // now place less than pivot elements(<pivot) at the begining, than place pivot element after that, after pivot element at its correct position all remaining elements are greater than pivot element(>pivot):
    for(j=first; j<=last-1; j++){
        if (v[j]<pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    // now i is pointing to the last element of (< pivot)
    // now place the pivot(v[last]) element at its correct pisition => (i+1)th position
    swap(v[i+1], v[last]);
    return (i+1);
}

// Quick Sort Algorithm:
void quickSort(vector<int> &v, int first, int last){
    // Base Case:
    if(first>=last) return;

    // Find the position of the pivot element:
    int pi = position(v, first, last);

    // Recursive call for quick sort subarrays:
    quickSort(v, first, pi-1);
    quickSort(v, pi+1, last);
}

int main(){
    // Input vector(array):
    vector<int> v = {10, 3, 7, 9, 1, 8};
    int n = v.size();
    int first = 0;
    int last = n-1;

    // Apply Quick Sort Algorithm:
    quickSort(v, first, last);

    // Print the sorted array:
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    
    return 0;
}