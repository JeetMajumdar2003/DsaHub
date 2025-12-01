#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert a node in BST from given array
Node* insertBST(Node* root, int val, int &successor) {
    // Base case
    if (root == NULL) {
        return new Node(val);
    }
    // Recursive case
    if (val < root->data) {
        // if val is less than root->data, then root->data is the successor(least greater element)
        successor = root->data;
        root->left = insertBST(root->left, val, successor);
    }
    else {
        root->right = insertBST(root->right, val, successor);
    }
    return root;
}

// Replace each element with the least greater element on its right
void replaceWithLeastGreaterElement(vector<int>& arr) {
    // Initialize root as NULL
    Node* root = NULL;
    // Traverse the array from right to left
    for (int i = arr.size() - 1; i >= 0; i--) {
        int successor = -1;
        // Insert the element in BST and get the successor(least greater element)
        root = insertBST(root, arr[i], successor);
        // Replace the element with the successor
        arr[i] = successor;
    }
    return;
}

int main() {
    // Given Array
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    // Replace each element with the least greater element on its right
    replaceWithLeastGreaterElement(arr);

    // Print the array after replacing each element with the least greater element on its right
    for (int ele : arr) {
        cout << ele << " ";
    }
    return 0;
}