#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Previous Greater Element: using index stack and reverse iteration
vector<int> findPreviousGreaterElements(const vector<int>& arr) {
    vector<int> result(arr.size(), -1); // Initialize result vector with -1

    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = arr[i]; // Set the previous greater element
            st.pop();
        }
        st.push(i);
    }

    return result;
}

// Previous Smaller Element: using index stack and reverse iteration
vector<int> findPreviousSmallerElements(const vector<int>& arr) {
    vector<int> result(arr.size(), -1); // Initialize result vector with -1

    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            result[st.top()] = arr[i]; // Set the previous smaller element
            st.pop();
        }
        st.push(i);
    }

    return result;
}


/*
// vector<int> findPreviousGreaterElements(const vector<int>& arr) {
//     vector<int> result;
//     stack<int> st;

//     for (int i = 0; i < arr.size(); i++) {
//         while (!st.empty() && st.top() <= arr[i]) {
//             st.pop();
//         }

//         if (st.empty()) {
//             result.push_back(-1);
//         } else {
//             result.push_back(st.top());
//         }

//         st.push(arr[i]);
//     }

//     return result;
// }

// vector<int> findPreviousSmallerElements(const vector<int>& arr) {
//     vector<int> result;
//     stack<int> st;

//     for (int i = 0; i < arr.size(); i++) {
//         while (!st.empty() && st.top() >= arr[i]) {
//             st.pop();
//         }

//         if (st.empty()) {
//             result.push_back(-1);
//         } else {
//             result.push_back(st.top());
//         }

//         st.push(arr[i]);
//     }

//     return result;
// }
*/

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    
    vector<int> previousGreater = findPreviousGreaterElements(arr);
    vector<int> previousSmaller = findPreviousSmallerElements(arr);

    cout << "Previous Greater Elements: ";
    for (int num : previousGreater) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Previous Smaller Elements: ";
    for (int num : previousSmaller) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}