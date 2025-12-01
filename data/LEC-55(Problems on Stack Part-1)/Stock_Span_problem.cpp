#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>    // for reverse function

using namespace std;

// Function to calculate the stock span
// vector<int> stockSpan(vector<int> &arr){
//     vector<int> ans;
//     stack<pair<int, int>> s;
//     for (int i = 0; i < arr.size(); i++){
//         if (s.empty()){
//             ans.push_back(-1);
//         }
//         else if (s.size() > 0 && s.top().first > arr[i]){
//             ans.push_back(s.top().second);
//         }
//         else if (s.size() > 0 && s.top().first <= arr[i]){
//             while (s.size() > 0 && s.top().first <= arr[i]){
//                 s.pop();
//             }
//             if (s.size() == 0){
//                 ans.push_back(-1);
//             }
//             else{
//                 ans.push_back(s.top().second);
//             }
//         }
//         s.push({arr[i], i});
//     }
//     for (int i = 0; i < ans.size(); i++){
//         ans[i] = i - ans[i];
//     }
//     return ans;
// }

// Optimized stock span: using previous greater element concept
vector<int> stockSpan(vector<int> &arr){
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < arr.size(); i++){
        while (!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }
        if (s.empty()){
            ans.push_back(i + 1);
        }
        else{
            ans.push_back(i - s.top());
        }
        s.push(i);
    }
    return ans;
}

// reverse the vector to get the previous greater element
vector<int> pgeIdx(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n, -1);
    reverse(arr.begin(), arr.end());
    stack<int> st;
    for (int i = 0; i < n; i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            ans[st.top()]=n-i-1;    // n-i-1 is the index of the previous greater element
            st.pop();
        }
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    reverse(arr.begin(), arr.end());
    return ans;
}

// Previous greater element: using reverse traversal
// vector<int> stockSpan(vector<int> &arr){
//     vector<int> ans;
//     stack<int> s;
//     for (int i = arr.size() - 1; i >= 0; i--){
//         while (!s.empty() && arr[s.top()] < arr[i]){
//             s.pop();
//         }
//         if (s.empty()){
//             ans.push_back(arr.size() - i);
//         }
//         else{
//             ans.push_back(s.top() - i);
//         }
//         s.push(i);
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }

int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = stockSpan(arr);
    for (int i = 0; i < ans.size(); i++){
        cout <<ans[i]<< " ";
    }
    cout <<endl;

    vector<int> pge = pgeIdx(arr);
    for (int i = 0; i < pge.size(); i++){
        cout <<i-pge[i]<< " ";
    }
    cout <<endl;
    return 0;
}