#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Bucket Sort Algorithm:
void bucketsort(float arr[], int n){
    // step-1: Create Buckets(2D array/vectors) of size n.
    vector<vector<float>> bucket(n, vector<float> ());

    // Step-2: Inserting elements into the bucket at (index = arr[i]*n)
    for (int i = 0; i < n; i++){ // O(n)
        int idx = arr[i]*n;
        bucket[idx].push_back(arr[i]);
    }
    
    // Step-3: Sorting individual buckets using Insertion Sort.(sort() function)
    for (int i = 0; i < n; i++){
        // check if bucket is empty or not
        if(!(bucket[i].empty())){
            sort(bucket[i].begin(), bucket[i].end());
        }
    }
    
    // Step-4: Concatenate all the buckets into the original array.
    int k=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < bucket[i].size(); j++){
            arr[k++] = bucket[i][j];
        }
    }
    
    return;
}

int main(){
    float arr[] = {0.13, 0.45 ,0.12, 0.89, 0.75, 0.63, 0.85, 0.39};
    int size = sizeof(arr)/sizeof(arr[0]);

    bucketsort(arr, size);

    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}