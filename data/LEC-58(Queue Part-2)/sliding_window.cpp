#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// Maximum element of window size k
vector<int> printKMax(int arr[], int n, int k){
    deque<int> dq;
    vector<int> v;
    // Process first k elements
    for(int i=0; i<k; i++){
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    v.push_back(arr[dq.front()]);
    // Process rest of the elements from k to n, if 
    for(int i=k; i<n; i++){
        if(dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        v.push_back(arr[dq.front()]);
    }
    return v;
}

int main(){
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    vector<int> v = printKMax(arr, n, k);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}