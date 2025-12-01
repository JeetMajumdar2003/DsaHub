#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


int pathSumUtil(Node* root, int targetSum, int currentSum, unordered_map<int, bool>& visited) {
    if (root == NULL) {
        return 0;
    }

    currentSum += root->data;

    if (currentSum == targetSum && root->left == NULL && root->right == NULL) {
        return 1;
    }

    int count = 0;

    if (visited.find(currentSum - targetSum) != visited.end()) {
        count += 1;
    }
    visited[currentSum] = true;

    count += pathSumUtil(root->left, targetSum, currentSum, visited);
    count += pathSumUtil(root->right, targetSum, currentSum, visited);

    visited.erase(currentSum);

    return count;
}


int pathSum(Node* root, int targetSum){
    unordered_map<int, bool> visited;
    int currentSum = 0;
    return pathSumUtil(root, targetSum, currentSum, visited);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Number of paths with sum 10: " << pathSum(root, 10) << endl;

    return 0;
}