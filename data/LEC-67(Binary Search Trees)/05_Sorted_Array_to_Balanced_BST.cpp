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

// Convert Sorted Array to Balanced BST:
Node* sortedArrayToBST(vector<int> &v, int start, int end){
    // Base condition
    if(start > end){
        return NULL;
    }
    // Find the middle element of the array
    int mid = (start + end) / 2;
    // Create a new node with the middle element
    Node* root = new Node(v[mid]);
    // Recursively convert left half of the array to BST
    root->left = sortedArrayToBST(v, start, mid - 1);
    // Recursively convert right half of the array to BST
    root->right = sortedArrayToBST(v, mid + 1, end);
    return root;
}

// printInOrder function to print the BST in InOrder Traversal
void printInOrder(Node* rootNode){
    if (rootNode == NULL) return;
    cout << rootNode->data << " ";
    printInOrder(rootNode->left);
    printInOrder(rootNode->right);
}

// Print BST in Level Order
void printLevelOrder(Node* rootNode){
    if (rootNode == NULL) return;
    queue<Node*> q;
    q.push(rootNode);
    while (!q.empty()){
        int nodesAtCurrentLevel = q.size(); // Number of nodes at the current level
        while(nodesAtCurrentLevel--){
            Node* currentNode = q.front();
            cout << currentNode->data << " ";
            q.pop();
            if (currentNode->left) q.push(currentNode->left);
            if (currentNode->right) q.push(currentNode->right);
        }
        cout << endl;
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    Node* root = sortedArrayToBST(v, 0, v.size() - 1);
    cout << "InOrder Traversal of the BST: ";
    printInOrder(root);
    cout << endl;
    printLevelOrder(root);

    return 0;
}