#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// M-1: first create inorder traversal from preorder and then construct BST from inorder and preorder: 
/**
 * Time complexity: O(nlogn) + O(n) = O(nlogn)
 * Space complexity: O(n) + O(n) + O(h) = O(n)
 */
class BST {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        int preStart = 0;
        int preEnd = preorder.size() - 1;
        int inStart = 0;
        int inEnd = inorder.size() - 1;

        unordered_map<int, int> inmap;
        for (int i = 0; i <= inEnd; i++) {
            inmap[inorder[i]] = i;  // storing value-index pairs
        }

        return bstFromPreorderHelper(preorder, preStart, preEnd, inorder, inStart, inEnd, inmap);
    }

private:
    TreeNode* bstFromPreorderHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> inmap) {
        // base case
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);  // root node

        // find the index of the root node in inorder tree
        int inRootIdx = inmap[preorder[preStart]];
        int leftSubtreeElements = inRootIdx - inStart;

        root->left = bstFromPreorderHelper(preorder, preStart + 1, preStart + leftSubtreeElements, inorder, inStart, inRootIdx - 1, inmap);
        root->right = bstFromPreorderHelper(preorder, preStart + leftSubtreeElements + 1, preEnd, inorder, inRootIdx + 1, inEnd, inmap);

        return root;
    }
};

// M-2: Using Upper Bound and Lower Bound
/**
 * Time complexity: O(n)
 * Space complexity: O(h) = O(n)
 */
class BST2 {
public:
    TreeNode* bstFromPreorder2(vector<int>& preorder) {
        int idx = 0;
        return bstFromPreorderHelper2(preorder, idx, INT_MIN, INT_MAX);
    }

private:
    TreeNode* bstFromPreorderHelper2(vector<int>& preorder, int& idx, int lower, int upper) {
        if (idx == preorder.size() || preorder[idx] < lower || preorder[idx] > upper) {
            return NULL;
        }

        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        root->left = bstFromPreorderHelper2(preorder, idx, lower, val);
        root->right = bstFromPreorderHelper2(preorder, idx, val, upper);

        return root;
    }
};

void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {4, 2, 1, 3, 6, 5, 7};

    // M-1: first create inorder traversal from preorder and then construct BST from inorder and preorder
    // BST bst;
    // TreeNode* root = bst.bstFromPreorder(preorder);

    // M-2: Using Upper Bound and Lower Bound
    BST2 bst;
    TreeNode* root = bst.bstFromPreorder2(preorder);
    
    // print inorder
    cout << "Inorder traversal of the constructed BST is: ";
    inorderTraversal(root);
    return 0;
}