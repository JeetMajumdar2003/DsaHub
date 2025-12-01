#include <iostream>
#include <vector>
using namespace std;

// Count Sort Function:
void countsort(vector<int> &v, int n, int pos){
    // Create a frequency/count array of size (10):
    vector<int> freq(10,0);
    for (int i = 0; i <= n-1; i++){
        freq[(v[i]/pos)%10]++;
    }
    
    // Calculate Cumulative frequency array(prefix sum frequency array):
    for (int i = 1; i <= 9; i++){
        freq[i] += freq[i-1];
    }
    
    // create an ans array:
    vector<int> ans(n);
    // now insert element from v array to ans array, using cumulative freq. array:
    for (int i = n-1; i >= 0; i--){
        ans[--freq[(v[i]/pos)%10]] = v[i];
    }
    
    // Copy back the ans array to original array:
    for (int i = 0; i < n; i++){
        v[i] = ans[i];
    }
    
}

// Rdaix Sort Algorithm:
void radixsort(vector<int> &v, int n){
    // finding max_ele element:
    int max_ele = INT_MIN;
    for (int i = 0; i < n; i++){
        max_ele = max(v[i], max_ele);
    }

    // Create a loop, which can go from 1 to maximum no. of digit of max_element:
    for (int pos = 1; (max_ele/pos) > 0; pos*=10){
        // Now apply count sort algorithm, only for position digit elements:
        countsort(v, n, pos);
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    
    // Radix Sort Function Call:
    radixsort(v, n);

    // print Sorted array
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}