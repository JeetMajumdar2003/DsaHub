#include <iostream>
#include <vector>
using namespace std;

// Binary Tree Node Class:
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        // Constructor
        Node(int value){
            data = value;
            left = NULL;
            right = NULL;
        }
};

// Helper function to check if the two binary trees are identical or not
bool checkIdenticalBSTHelper(vector<int> &arr1, vector<int> &arr2, int i, int j, int n, int m, int min, int max){
    // Find the first element in the arr1 which lies within the range(min, max)
    int k1 = i;
    for(k1 = i; k1 < n; k1++){
        if(arr1[k1] > min && arr1[k1] < max){
            break;
        }
    }
    // Find the first element in the arr2 which lies within the range(min, max)
    int k2 = j;
    for(k2 = j; k2 < m; k2++){
        if(arr2[k2] > min && arr2[k2] < max){
            break;
        }
    }
    // now k1 and k2 are the indices of the first elements in arr1 and arr2 which lie within the range(min, max)

    // if no such element is found, means both the arrays are exhausted and we have reached the leaf node
    // if both elements are leaf nodes, return true
    if(k1 == n && k2 == m){
        return true;
    }

    // if only one of the elements is a leaf node, return false
    if((k1 == n && k2 != m) || (k1 != n && k2 == m)){   // (k1 == n ^ k2 == m) can also be used(Exclusive OR)
        return false;
    }

    // if the elements are not equal, return false
    if(arr1[k1] != arr2[k2]){
        return false;
    }

    // recursively check the left and right subtrees, if they are identical or not
    return checkIdenticalBSTHelper(arr1, arr2, k1 + 1, k2 + 1, n, m, min, arr1[k1]) && checkIdenticalBSTHelper(arr1, arr2, k1 + 1, k2 + 1, n, m, arr1[k1], max);
}

// Function to check if the two binary trees are identical or not
bool checkIdenticalBST(vector<int> arr1, vector<int> arr2){
    int i = 0, j = 0;
    int n = arr1.size();
    int m = arr2.size();
    int min = INT_MIN;
    int max = INT_MAX;

    return checkIdenticalBSTHelper(arr1, arr2, i, j, n, m, min, max);
} 

int main() {
    // Create two arrays
    vector<int> arr1 = {4, 2, 5, 1, 3};
    vector<int> arr2 = {4, 5, 2, 3, 1};

    // Check if the two arrays represent the same BST or not
    if(checkIdenticalBST(arr1, arr2)){
        cout << "The two arrays represent the SAME BST." << endl;
    } else {
        cout << "The two arrays do NOT represent the SAME BST." << endl;
    }
    
    return 0;
}