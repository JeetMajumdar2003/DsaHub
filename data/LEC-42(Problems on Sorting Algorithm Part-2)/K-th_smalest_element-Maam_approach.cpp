#include <bits/stdc++.h>
using namespace std;

/*My Approach Using Quick Sort: Place the kth smalest element at its correct position and print the kth smalest element*/

// Pivot element position function:
int position(vector<int> &v, int l, int r){
    // Select the Pivot element:
    int pivot = v[r];

    // initialize two indexes(i, j):
    int i = l-1;
    int j=l;

    // now place less than pivot elements(<pivot) at the begining, than place pivot element after that, after pivot element at its correct position all remaining elements are greater than pivot element(>pivot):
    for (int j = l; j <= r-1; j++){
        if(v[j]<pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    // now i is pointing to the r element of (< pivot)
    // now place the pivot(v[r]) element at its correct pisition => (i+1)th position
    swap(v[i+1], v[r]);
    return i+1;
}

int kThSmalest(vector<int> &v, int l, int r, int k){
    if (k>0 && k<=r-l+1){
        // Find the position of the pivot element:
        int pos = position(v, l, r);
        if (pos-l == k-1){
            return v[pos];
        }
        else if (pos-l>k-1){
            return kThSmalest(v, l, pos-1, k);
        }
        else{
            return kThSmalest(v, pos+1, r, k-(pos-l+1));
        }
    }
    return INT_MAX;
}

int main()
{
    // Input vector(array):
    vector<int> v = {3, 5, 2, 1, 4, 6, 8, 7};
    int n = v.size();
    int l = 0;
    int r = n-1;
    int k = 5;

    // Apply Quick Sort Algorithm for kth smallest element:
    

    cout<<"kth smallest element is: " << kThSmalest(v, l, r, k) << endl; // kth smallest element

    // Print the sorted array:
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
}