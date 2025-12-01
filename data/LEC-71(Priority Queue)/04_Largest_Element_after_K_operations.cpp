#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int longestElementAfterKOperations(vector<int> v, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;  // min heap
    for(int i=0; i<n; i++){
        pq.push(v[i]);
    }

    while(k--){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int product = first * second;
        pq.push(product);
    }

    // remove all elements except the largest element
    while(pq.size() > 1){
        pq.pop();
    }

    return pq.top();
}

int main(){
    int k;
    cin>>k;
    vector<int> v = {2, 4, 3, 1, 5};
    int n = v.size();

    int longestElement = longestElementAfterKOperations(v, n, k);

    cout<<longestElement<<endl;

    return 0;
}