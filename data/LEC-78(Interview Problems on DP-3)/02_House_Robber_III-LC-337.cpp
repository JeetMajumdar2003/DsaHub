/** House Robber III - LeetCode 337(https://leetcode.com/problems/house-robber-iii/)
 *  Problem Statement:
 *  The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root."
 *  Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in
 *  this place are arranged in a binary tree".
 *
 *  It will automatically contact the police if two directly-linked houses were broken into on the same night.
 *
 *  Determine the maximum amount of money the thief can rob tonight without alerting the police by "robbing two directly-linked houses."
 *
 *  Example 1:
 *  Input: root = [3,2,3,null,3,null,1]
 *          3
 *         / \
 *        2   3
 *         \   \
 *          3   1
 *  Output: 7
 *  Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 * Example 2:
 * Input: root = [3,4,5,1,3,null,1]
 *        3
 *       / \
 *      4   5
 *     / \   \
 *    1   3   1
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 10^4].
 * 0 <= Node.val <= 10^4
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    // Constructor
    Node() : val(0), left(NULL), right(NULL) {}
    Node(int x) : val(x), left(NULL), right(NULL) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

// Recursive Solution:
// Function to calculate the maximum amount of money the thief can rob
int rob(Node *root)
{
    if (!root)
        return 0;

    int moneyWithRoot = root->val;
    if (root->left)
    {
        moneyWithRoot += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right)
    {
        moneyWithRoot += rob(root->right->left) + rob(root->right->right);
    }

    int moneyWithoutRoot = rob(root->left) + rob(root->right);

    return max(moneyWithRoot, moneyWithoutRoot);
}

int rob2(Node *root, bool isParentRobbed)
{
    if (!root)
        return 0;

    // If the parent is robbed, we cannot rob this node
    if (isParentRobbed)
    {
        return rob2(root->left, false) + rob2(root->right, false);
    }

    // If the parent is not robbed, we have two choices:
    // 1. Rob this node and skip its children
    int moneyWithRoot = root->val + rob2(root->left, true) + rob2(root->right, true);

    // 2. Skip this node and consider its children
    int moneyWithoutRoot = rob2(root->left, false) + rob2(root->right, false);

    return max(moneyWithRoot, moneyWithoutRoot);
}

// Dynamic Programming Solution:
unordered_map<Node *, int> robbedCache;
unordered_map<Node *, int> notRobbedCache;
int robDP(Node* root, bool isParentRobbed) {
    if (!root) return 0;

    // Check if the result is already cached
    if (isParentRobbed && robbedCache.find(root) != robbedCache.end()) {
        return robbedCache[root];
    }
    if (!isParentRobbed && notRobbedCache.find(root) != notRobbedCache.end()) {
        return notRobbedCache[root];
    }

    // If the parent is robbed, we cannot rob this node
    if (isParentRobbed) {
        return robbedCache[root] = robDP(root->left, false) + robDP(root->right, false);
    }

    // If the parent is not robbed, we have two choices:
    // 1. Rob this node and skip its children
    int moneyWithRoot = root->val + robDP(root->left, true) + robDP(root->right, true);

    // 2. Skip this node and consider its children
    int moneyWithoutRoot = robDP(root->left, false) + robDP(root->right, false);

    int result = max(moneyWithRoot, moneyWithoutRoot);

    // Cache the result
    if (isParentRobbed) {
        robbedCache[root] = result;
    } else {
        notRobbedCache[root] = result;
    }

    return result;
}

int robDP2(Node *root){
    if (!root)
        return 0;

    if (robbedCache.find(root) != robbedCache.end())
        return robbedCache[root];
    if (notRobbedCache.find(root) != notRobbedCache.end())
        return notRobbedCache[root];

    int moneyWithRoot = root->val;

    if (root->left)
        moneyWithRoot += robDP2(root->left->left) + robDP2(root->left->right);
    if (root->right)
        moneyWithRoot += robDP2(root->right->left) + robDP2(root->right->right);

    int moneyWithoutRoot = robDP2(root->left) + robDP2(root->right);

    int result = max(moneyWithRoot, moneyWithoutRoot);

    robbedCache[root] = result;
    notRobbedCache[root] = result;

    return result;
}

int main()
{
    // Example 1:
    Node *root1 = new Node(3);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(3);
    root1->right->right = new Node(1);

    // Example 2:
    Node *root2 = new Node(3);
    root2->left = new Node(4);
    root2->right = new Node(5);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    root2->right->right = new Node(1);

    // Function to calculate the maximum amount of money the thief can rob
    int profit1 = rob(root1);
    int profit2 = rob(root2);
    int profit12 = rob2(root1, false);
    int profit22 = rob2(root2, false);

    cout << "Maximum amount of money the thief can rob from tree 1: " << profit1 << endl;  // Output: 7
    cout << "Maximum amount of money the thief can rob from tree 2: " << profit2 << endl;  // Output: 9
    cout << "Maximum amount of money the thief can rob from tree 1: " << profit12 << endl; // Output: 7
    cout << "Maximum amount of money the thief can rob from tree 2: " << profit22 << endl; // Output: 9

    // DP Solution
    int dpProfit1 = robDP(root1, false);
    int dpProfit2 = robDP(root2, false);
    int dpProfit12 = robDP2(root1);
    int dpProfit22 = robDP2(root2);
    cout << "DP Solution - Maximum amount of money the thief can rob from tree 1: " << dpProfit1 << endl;  // Output: 7
    cout << "DP Solution - Maximum amount of money the thief can rob from tree 2: " << dpProfit2 << endl;  // Output: 9
    cout << "DP Solution - Maximum amount of money the thief can rob from tree 1: " << dpProfit12 << endl; // Output: 7
    cout << "DP Solution - Maximum amount of money the thief can rob from tree 2: " << dpProfit22 << endl; // Output: 9
    return 0;
}