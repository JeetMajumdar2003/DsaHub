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

// Maximum Depth:
int maximumDepth(Node* rootNode){
    // Base Case
    // if (rootNode == NULL) return 0;
    if (rootNode->left == NULL and rootNode->right == NULL) return 1;

    // Recursive Case
    int leftDepth = 0, rightDepth = 0;
    if (rootNode->left != NULL) leftDepth = maximumDepth(rootNode->left);
    if (rootNode->right != NULL) rightDepth = maximumDepth(rootNode->right);

    // cout << "Node: " << rootNode->data << " Depth: " << max(leftDepth, rightDepth) + 1 << endl;
    int maxDepth = max(leftDepth, rightDepth) + 1;
    return maxDepth;
}

int main() {
    // Create a binary tree
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    root->left->right->left = new Node(3);

    cout << "Max Depth: " << maximumDepth(root) << endl;
    
    return 0;
}

/**
 * Tree:
 *         2
 *       /   \
 *      4    10
 *     / \     \
 *    6   5    11
 *       /
 *      3
 * Max Depth: 4 (2->4->5->3)
 */