#include <iostream>
using namespace std;

// Max Path Sum in tree

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int maxPathSum(Node* root, int& maxSum) {
    if (root == NULL) {
        return 0;
    }

    int leftMaxSum = max(0, maxPathSum(root->left, maxSum));
    int rightMaxSum = max(0, maxPathSum(root->right, maxSum));
    maxSum = max(maxSum, (root->data + leftMaxSum + rightMaxSum));
    return (root->data + max(leftMaxSum, rightMaxSum));

    // int leftSum = maxPathSum(root->left, maxSum);
    // int rightSum = maxPathSum(root->right, maxSum);
    // int currentSum = max(root->data, max(root->data + leftSum, root->data + rightSum));
    // maxSum = max(maxSum, max(currentSum, root->data + leftSum + rightSum));
    // return currentSum;

}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(6);
    root->right->left = new Node(4);
    root->right->right = new Node(5);


    int maxSum = INT_MIN;
    maxPathSum(root, maxSum);
    cout << "Maximum path sum: " << maxSum << endl;

    return 0;
}
