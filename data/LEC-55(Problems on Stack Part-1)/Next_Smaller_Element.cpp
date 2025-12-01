#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to find the next smaller element for each element in the array
vector<int> findNextSmallerElement(const vector<int>& arr) {
    vector<int> result(arr.size(), -1); // Initialize result vector with -1

    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) { // If the current element is smaller than the top element of the stack then pop the top element and set the next smaller element of the top element as the current element
            result[st.top()] = arr[i]; // Set the next smaller element
            st.pop();
        }
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 8, 2, 1, 5, 10};
    vector<int> nextSmaller = findNextSmallerElement(arr);

    cout << "Next smaller elements: ";
    for (int i = 0; i < nextSmaller.size(); i++) {
        cout << nextSmaller[i] << " ";
    }
    cout << endl;

    return 0;
}