#include<iostream>
#include<stack>
using namespace std;

// Next Greater Element (NGE) of an element X in an array is the first greater element on the right side of X in the array.
// Brute Force Solution: (Linear Search)
int* nextGreaterElement(int* arr, int n) {
    int* res = new int[n];
    for(int i=0; i<n; i++) {
        res[i] = -1;
        for(int j=i+1; j<n; j++) {
            if(arr[j] > arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
    }
    return res;
}

// Using Stack: (Optimized Solution) Index of the array is pushed into the stack
int* NGEStackIndex(int* arr, int n){
    stack<int> st;
    // st.push(0);
    int* res = new int[n];
    for (int i = 0; i < n; i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            res[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()){
        res[st.top()]=-1;
        st.pop();
    }
    return res;
}

// Using Stack: (Optimized Solution) Element of the array is pushed into the stack
int* NGEStackElement(int* arr, int n) {
    int* res = new int[n];
    stack<int> s;
    for(int i=n-1; i>=0; i--) {
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return res;
}

// Main Function
int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    // 
    // int* res = nextGreaterElement(arr, n);
    int* res = NGEStackIndex(arr, n);
    // int* res = NGEStackElement(arr, n);


    for(int i=0; i<n; i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}