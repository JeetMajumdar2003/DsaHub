#include <iostream>
#include <queue>
#include <stack>
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

// Reverse Level Order Traversal: (BFS)
void ReverseLevelOrderTraversal(Node* rootNode){
    // Base Case
    if (rootNode == NULL) return;

    // Create a queue
    queue<Node*> q;
    // Create a stack
    stack<Node*> s;

    // Push the root node
    q.push(rootNode);

    // Iterate until the queue is empty
    while (!q.empty()){
        // Get the front element of the queue
        Node* current = q.front();

        // Pop the front element
        q.pop();
        // Push the current node into the stack
        s.push(current);

        // First, push the right child into the queue then the left child
        // If the right child exists, push it into the queue
        if (current->right != NULL) q.push(current->right);
        // If the left child exists, push it into the queue
        if (current->left != NULL) q.push(current->left);
    }

    // Print the stack
    while (!s.empty()){
        cout << s.top()->data << " ";
        s.pop();
    }

    return;
}

int main() {
    // Create a binary tree
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);

    // Reverse Level Order Traversal
    ReverseLevelOrderTraversal(root);

    return 0;
}

/**
 * Tree:
 *         2
 *       /   \
 *      4    10
 *     / \     \
 *    6   5    11
 * Output: 6 5 11 4 10 2
 */