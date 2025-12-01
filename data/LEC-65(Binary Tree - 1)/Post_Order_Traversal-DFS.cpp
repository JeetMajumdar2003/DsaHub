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

// Post-Order Traversal:
void postOrderTraversal(Node* rootNode){
    // Base Case
    if (rootNode == NULL) return;

    // Recursive Case
    postOrderTraversal(rootNode->left);
    postOrderTraversal(rootNode->right);
    // Print the root node
    cout<<rootNode->data<<" ";
}

int main() {
    // Create a binary tree
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);

    // post-Order Traversal
    postOrderTraversal(root);
    
    return 0;
}

/**
 * Tree:
 *         2
 *       /   \
 *      4    10
 *     / \     \
 *    6   5    11
 * Output: 6 5 4 11 10 2
 */