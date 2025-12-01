#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// Find the largest rectangle in a histogram

// Brute Force Solution: (Linear Search)
// int largestRectangleArea(vector<int>& heights) {
//     int n = heights.size();
//     int maxArea = 0;
//     for (int i = 0; i < n; i++){
//         int minHeight = heights[i];
//         for (int j = i; j < n; j++){
//             minHeight = min(minHeight, heights[j]);
//             maxArea = max(maxArea, minHeight * (j - i + 1));
//         }
//     }
//     return maxArea;
// }

// Using Stack: (Optimized Solution)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    // Create two vectors to store the prev and next indices of the current element which are smaller than the current element: (Next Smaller Element concept & Previous Smaller Element concept)
    vector<int> prev(n), next(n);
    // Find the previous smaller element index(PSI) for each element
    for (int i = 0; i < n; i++){
        while (!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }
        if (s.empty()){
            prev[i] = -1;    // If there is no previous smaller element then the index is -1
        }
        else{
            prev[i] = s.top();  // If there is a previous smaller element then the index is the top element of the stack
        }
        s.push(i);
    }
    // Clear the stack
    while (!s.empty()){
        s.pop();
    }
    // Find the next smaller element index(NSI) for each element
    for (int i = n - 1; i >= 0; i--){
        while (!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }
        if (s.empty()){
            next[i] = n;    // If there is no next smaller element then the index is n
        }
        else{
            next[i] = s.top();  // If there is a next smaller element then the index is the top element of the stack
        }
        s.push(i);
    }
    // Calculate the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++){
        maxArea = max(maxArea, heights[i] * (next[i] - prev[i] - 1));
    }
    return maxArea;
}

// Using Stack: (Optimized Solution)
int largestRectangleArea2(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    int maxArea = 0;
    for (int i = 0; i <= n; i++){
        while (!s.empty() && (i == n || heights[s.top()] >= heights[i])){
            int h = heights[s.top()];
            s.pop();
            int w;
            if (s.empty()) {
                w = i;
            } else {
                w = i - s.top() - 1;
            }
            // cout << h << " " << w << endl;
            maxArea = max(maxArea, h * w);
        }
        s.push(i);
    }
    return maxArea;
}

// Using Stack: (Optimized Solution)- Sanket Singh Sir's approach
int LRA(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    vector<int> nsi(n, n), psi(n, -1);
    int maxArea = 0;
    for (int i = 0; i <= n; i++){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            int h = heights[s.top()];   // height of the top element of the stack
            int j = s.top();    // index of the top element of the stack
            s.pop();    // pop the top element of the stack
            int w;  
            nsi[j] = i;    // next smaller element index of the top element of the stack
            psi[j] = (s.empty() ? -1 : s.top());   // previous smaller element index of the top element of the stack
            w = nsi[j] - psi[j] - 1; // width of the rectangle formed by the top element of the stack
            maxArea = max(maxArea, h * w);
            cout << nsi[j] << " " << psi[j] << " " << h << " " << w << " " << maxArea << endl;
        }
        s.push(i);
    }
    return maxArea;
}

// Main Function
int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 11};
    cout << largestRectangleArea(heights) << endl;
    cout << largestRectangleArea2(heights) << endl;
    cout << LRA(heights) << endl;
    return 0;
}