#include <iostream>
#include <vector>
using namespace std;

// Count Sort Function:
void countsort(vector<int> &v, int n){
    // finding max_ele element:
    int max_ele = INT_MIN;
    for (int i = 0; i < n; i++){
        max_ele = max(v[i], max_ele);
        // if (v[i]>max_ele){
        //     max_ele = v[i];
        // }
    }
    
    // Create a frequency/count array of size (max_ele+1):
    vector<int> freq(max_ele+1,0);
    for (int i = 0; i <= n-1; i++){
        freq[v[i]]++;
    }
    
    // Calculate Cumulative frequency array(prefix sum frequency array):
    for (int i = 1; i <= max_ele; i++){
        freq[i] += freq[i-1];
    }
    
    // create an ans array:
    vector<int> ans(n);
    // now insert element from v array to ans array, using cumulative freq. array:
    for (int i = n-1; i >= 0; i--){
        ans[--freq[v[i]]] = v[i];
    }
    
    // Copy back the ans array to original array:
    for (int i = 0; i < n; i++){
        v[i] = ans[i];
    }
    
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    
    // Count Sort Function Call:
    countsort(v, n);

    // print Sorted array
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}