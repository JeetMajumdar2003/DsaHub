#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Bucket Sort Algorithm:
void bucketsort(float arr[], int n){
    // step-1: Create Buckets(2D array/vectors) of size n.
    vector<vector<float>> bucket(n, vector<float> ());

    // Step-2: Inserting elements into the bucket at:(My approach)
    /*
    ** Index calculation:
    ** 1. First calculate the range of elements:
    **    range = (max_element - min_element);
    ** 2. Now, calculate the index of each element:
    **    index = (arr[i] - min_element)/range
    */
    // 1. First calculate the range of elements:
    int range = (*max_element(arr, arr+n) - *min_element(arr, arr+n)); // here max_element() and min_element() returns the address of the max and min element respectively. So, we have to dereference(*) them to get the value.
    //  2. Now, calculate the index of each element and insert them into the bucket:
    for (int i = 0; i < n; i++){
        int idx = (arr[i] - *min_element(arr, arr+n))/range;
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
    float arr[] = {8.13, 6.45 ,2.12, 7.89, 2.75, 6.63, 9.85, 10.39};
    int size = sizeof(arr)/sizeof(arr[0]);

    bucketsort(arr, size);

    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}