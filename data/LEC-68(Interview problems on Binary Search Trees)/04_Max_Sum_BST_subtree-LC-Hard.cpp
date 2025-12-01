#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Create a class to store the information of the subtree
class NodeInfo {
public:
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
    int size;

    NodeInfo(bool isBST, int minVal, int maxVal, int sum, int size) {
        this->isBST = isBST;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->sum = sum;
        this->size = size;
    }
};

// Helper function to calculate the maximum Sum BST subtree
NodeInfo* maxSumBST(TreeNode* root, int& maxSum, int& size) {
    // Base case
    if (root == NULL) {
        return new NodeInfo(true, INT_MAX, INT_MIN, 0, 0);
    }

    // Recursive calls
    NodeInfo* left = maxSumBST(root->left, maxSum, size);
    NodeInfo* right = maxSumBST(root->right, maxSum, size);

    // Check if the current subtree is a BST
    if (left->isBST && right->isBST && root->val > left->maxVal && root->val < right->minVal) {
        int sum = left->sum + right->sum + root->val;
        size = left->size + right->size + 1;
        maxSum = max(maxSum, sum);
        return new NodeInfo(true, min(left->minVal, root->val), max(right->maxVal, root->val), sum, size);
    }

    // If the current subtree is not a BST
    return new NodeInfo(false, INT_MIN, INT_MAX, max(left->sum, right->sum), max(left->size, right->size));
}


int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);
    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(70);
    root->right->right->left = new TreeNode(65);
    root->right->right->right = new TreeNode(80);

    // Calculate the maximum Sum BST subtree
    int maxSum = 0;
    int size = 0;
    maxSumBST(root, maxSum, size);
    cout << "Maximum Sum BST subtree: " << maxSum << endl;
    cout << "Size of the maximum Sum BST subtree: " << size << endl;

    return 0;
}

/**
 * Time Complexity: O(N)
 * Space Complexity: O(H)
 * N = Number of nodes in the binary tree
 * H = Height of the binary tree
 *          50
 *         /  \
 *       30   60
 *      / \   / \
 *     5  20 45 70
 *             / \
 *            65 80
 */