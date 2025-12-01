#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarray(vector<int> &arr, int n){
    // calculate prefix sum
    // for (int i = 1; i < n; i++){
    //     arr[i] += arr[i-1];
    // }
    int prefixSum = 0;

    unordered_map<int, int> mp;
    int max_len = 0;
    for(int i=0; i<n; i++){
        prefixSum += arr[i];
        if(prefixSum==0)
            max_len++;
        if(mp.count(prefixSum)){
            max_len = max(max_len, i-mp[arr[i]]);
        }
        else{
            mp[arr[i]] = i;
        }
    }
    return max_len;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout<< "length of longest subarray with sum 0 is: "<<longestSubarray(arr, n)<<endl;
    
    return 0;
}