#include <iostream>
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

// Level-Order Traversal: (BFS)
void LevelOrderTraversal(Node* rootNode){
    // Base Case
    if (rootNode == NULL) return;

    // Create a queue
    queue<Node*> q;

    // Push the root node
    q.push(rootNode);

    // Iterate until the queue is empty
    while (!q.empty()){
        // Get the front element of the queue
        Node* current = q.front();
        // Print the front element
        cout << current->data << " ";
        // Pop the front element
        q.pop();

        // If the left child exists, push it into the queue
        if (current->left != NULL) q.push(current->left);
        // If the right child exists, push it into the queue
        if (current->right != NULL) q.push(current->right);
    }

    return;
}


// Level-Order Traversal: (BFS)
void LevelOrderTraversal2(Node* rootNode){
    // Base Case
    if (rootNode == NULL) return;

    // Create a queue
    queue<Node*> q;

    // Push the root node
    q.push(rootNode);

    // Iterate until the queue is empty
    while (!q.empty()){
        
        int nodesAtCurrentLevel = q.size(); // Number of nodes at the current level
        while(nodesAtCurrentLevel--){
            // Get the front element of the queue
            Node* currentNode = q.front();
            // Print the front element
            cout << currentNode->data << " ";
            // Pop the front element
            q.pop();

            // If the left child exists, push it into the queue
            if (currentNode->left) q.push(currentNode->left);
            // If the right child exists, push it into the queue
            if (currentNode->right) q.push(currentNode->right);
        }
        cout << endl;
    }
}

int main() {
    // Create a binary tree
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);

    // Level-Order Traversal
    LevelOrderTraversal(root);
    cout << endl;
    LevelOrderTraversal2(root);
    
    return 0;
}

/**
 * Tree:
 *         2
 *       /   \
 *      4    10
 *     / \     \
 *    6   5    11
 * Output: 2 4 10 6 5 11
 */