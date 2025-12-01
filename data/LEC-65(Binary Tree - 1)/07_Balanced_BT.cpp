#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) { 
        val = x; 
        left = nullptr; 
        right = nullptr; 
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeightBalance(root) != -1;
    }
    
private:
    int getHeightBalance(TreeNode* node) {
        // An empty tree is balanced and its height is 0
        if (node == nullptr) {
            return 0;
        }
        
        // Recursively check the height of the left and right subtrees
        int leftHeight = getHeightBalance(node->left);
        int rightHeight = getHeightBalance(node->right);
        
        // If either subtree is unbalanced, propagate -1 upwards
        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        }
        
        // If the height difference is greater than 1, the tree is unbalanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        // If balanced, return the height of this subtree
        return 1 + max(leftHeight, rightHeight);
    }
};

// How about bottom up approach? using function
int bottomUpApproach(TreeNode* root, int& height) {
    if (root == nullptr) {
        height = 0;
        return true;
    }
    
    int leftHeight = 0, rightHeight = 0;
    bool leftBalanced = bottomUpApproach(root->left, leftHeight);
    bool rightBalanced = bottomUpApproach(root->right, rightHeight);
    
    height = 1 + max(leftHeight, rightHeight);
    
    if (!leftBalanced || !rightBalanced) {
        return false;
    }
    
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    
    return true;
}

// using vector
vector<int> bottomUpApproach(TreeNode* root) {
    if (root == nullptr) {
        return {0, true};
    }
    
    vector<int> left = bottomUpApproach(root->left);
    vector<int> right = bottomUpApproach(root->right);
    
    int height = 1 + max(left[0], right[0]);
    
    if (!left[1] || !right[1]) {
        return {height, false};
    }
    
    if (abs(left[0] - right[0]) > 1) {
        return {height, false};
    }
    
    return {height, true};
}


int main() {

    // Create a binary tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(4);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(11);
    root->left->right->left = new TreeNode(3);

    // Check if the tree is balanced
    Solution s;
    cout << "Is Balanced: " << s.isBalanced(root) << endl;

    // Check if the tree is balanced using bottom up approach
    int height = 0;
    cout << "Is Balanced: " << bottomUpApproach(root, height) << endl;

    // Check if the tree is balanced using bottom up approach with vector
    vector<int> result = bottomUpApproach(root);
    cout << "Is Balanced: " << result[1] << endl;

    return 0;
}

/**
 * Tree:
 *        2
 *      /   \
 *     4    10
 *    / \     \
 *   6   5    11
 *      /
 *     3
 */


/**
 * Calculate Time and Space Complexity for the above solution:
 * 1. Balanced BT using top down approach:
 *   - Time Complexity => O(N^2)
 *   - Space Complexity => O(N)
 * 2. Balanced BT using bottom up approach:
 *  - Time Complexity => O(N)
 *  - Space Complexity => O(N)
 * 3. Balanced BT using bottom up approach with vector:
 *  - Time Complexity => O(N)
 *  - Space Complexity => O(N)
 */