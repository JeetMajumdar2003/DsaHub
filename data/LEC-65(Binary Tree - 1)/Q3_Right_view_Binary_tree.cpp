#include <iostream>
#include <vector>
#include <queue>
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

// Right View of a Binary Tree:
vector<int> rightViewBinaryTree(Node* rootNode){

    // Declare a vector to store the right view of the binary tree
    vector<int> rightView;

    // Base Case
    if (rootNode == NULL) return rightView;

    // Create a queue
    queue<Node*> q;

    // Push the root node
    q.push(rootNode);

    // Iterate until the queue is empty
    while (!q.empty()){
        
        int nodesAtCurrentLevel = q.size(); // Number of nodes at the current level
        while(nodesAtCurrentLevel){
            // Get the front element of the queue
            Node* currentNode = q.front();
            // Pop the front element
            q.pop();

            // If it is the last node at the current level, add it to the right view
            if (nodesAtCurrentLevel == 1) rightView.push_back(currentNode->data);

            // If the left child exists, push it into the queue
            if (currentNode->left) q.push(currentNode->left);
            // If the right child exists, push it into the queue
            if (currentNode->right) q.push(currentNode->right);

            nodesAtCurrentLevel--;  // Decrement the number of nodes at the current level
        }
    }
    return rightView;
}

int main() {
    // Create a binary tree
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->left->right = new Node(12);
    root->left->right = new Node(5);
    root->right->right = new Node(11);

    // Right View of a Binary Tree
    vector<int> rightView = rightViewBinaryTree(root);
    cout << "Right View: ";
    for (int i = 0; i < rightView.size(); i++) 
        cout << rightView[i] << " ";
    
    return 0;
}

/**
 * Tree:
 *         2           
 *       /   \         (. .)
 *      4    10       / | | \ 
 *     / \     \        | |
 *    6   5    11       / \
 *     \
 *      12
 * Right View: 2 10 11 12
 */