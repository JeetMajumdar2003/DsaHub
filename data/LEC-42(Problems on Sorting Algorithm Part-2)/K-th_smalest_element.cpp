#include <bits/stdc++.h>
using namespace std;

/*My Approach Using Quick Sort: Place the kth smalest element at its correct position and print the kth smalest element*/

// Pivot element position function:
int position(vector<int> &v, int first, int last){
    // Select the Pivot element:
    int pivot = v[last];

    // initialize two indexes(i, j):
    int i = first-1;
    int j=first;

    // now place less than pivot elements(<pivot) at the begining, than place pivot element after that, after pivot element at its correct position all remaining elements are greater than pivot element(>pivot):
    for (int j = first; j <= last-1; j++){
        if(v[j]<pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    // now i is pointing to the last element of (< pivot)
    // now place the pivot(v[last]) element at its correct pisition => (i+1)th position
    swap(v[i+1], v[last]);
    return i+1;
}

void kThSmalest(vector<int> &v, int first, int last, int k){
    if (first>=last) return;

    // find the position of the pivot element:
    int pi = position(v, first, last);

    // Now check in which subarray kth smalest element will be present:
    if ((k-1)<pi){  // call left sub array
        kThSmalest(v, first, pi-1, k);
    }
    else{  // call right sub array
        kThSmalest(v, pi+1, last, k);
    }
    
}

int main()
{
    // Input vector(array):
    vector<int> v = {3, 5, 2, 1, 4, 6, 8, 7};
    int n = v.size();
    int first = 0;
    int last = n-1;
    int k = 5;

    // Apply Quick Sort Algorithm for kth smallest element:
    kThSmalest(v, first, last, k);

    cout<<"kth smallest element is: " << v[k-1] << endl; // kth smallest element

    // Print the sorted array:
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
}