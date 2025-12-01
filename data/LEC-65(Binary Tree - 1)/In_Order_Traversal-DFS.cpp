#include <iostream>
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

// In-Order Traversal:
void inOrderTraversal(Node* rootNode){
    // Base Case
    if (rootNode == NULL) return;

    // Recursive Case
    inOrderTraversal(rootNode->left);
    cout<<rootNode->data<<" ";    // Print the root node
    inOrderTraversal(rootNode->right);
}

int main() {
    // Create a binary tree
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);

    // in-Order Traversal
    inOrderTraversal(root);
    
    return 0;
}

/**
 * Tree:
 *         2
 *       /   \
 *      4    10
 *     / \     \
 *    6   5    11
 * Output: 6 4 5 2 10 11
 */