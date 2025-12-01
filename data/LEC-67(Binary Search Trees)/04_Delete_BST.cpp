#include <iostream>
#include <queue>
using namespace std;

// Binary Tree Node Class:
class Node{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
// Binary Search Tree Class:
class BST{
public:
    Node *root;

    // Constructor
    BST(){
        root = NULL;
    }
};
// Insert Elements Recursive:
Node* insertBSTRecursive(Node* root, int value){
    // base case
    if (root == NULL){
        Node* newNode = new Node(value);
        return newNode;
    }

    if (root->data > value){
        root->left = insertBSTRecursive(root->left, value);
    }
    else{
        root->right = insertBSTRecursive(root->right, value);
    }
    return root;
}

// Print BST in Level Order
void printLevelOrder(Node* root){
    // Base condition
    if (root == NULL){
        return;
    }
    // Create a queue
    queue<Node*> q;
    // Push root node to the queue
    q.push(root);
    q.push(NULL);
    // Loop until queue is empty
    while (!q.empty()){
        int nodeInCurrentLevel = q.size();
        // Loop through the current level nodes
        while (nodeInCurrentLevel--){
            // Get the front element of the queue
            Node* node = q.front();
            q.pop();

            if (node != NULL){
                // Display the node data
                cout<<node->data<<" ";
                // If left child is not NULL, then push it to the queue
                if (node->left != NULL){
                    q.push(node->left);
                }
                // If right child is not NULL, then push it to the queue
                if (node->right != NULL){
                    q.push(node->right);
                }
            }
            else{
                cout<<endl;
                if (!q.empty()){
                    q.push(NULL);
                }
            }
        }
    }
    return;
}


// largest element in the left subtree: Inorder Predecessor
Node* largestNodeInLeftSubTreeBST(Node* root){
    // Node* current = root;
    while (root && root->right != NULL){
        root = root->right;
    }
    return root;
}
// Smallest element in the right subtree:   Inorder Successor
Node* smallestNodeInRightSubTreeBST(Node* root){
    Node* current = root;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}

// Delete Element:
Node* deleteNode(Node* &root, int key){
    // Base case
    if (root == NULL) return NULL;

    // Recursive case
    if (root->data > key){
        root->left = deleteNode(root->left, key);
    }
    else if (root->data < key){
        root->right = deleteNode(root->right, key);
    }
    else{
        // 1. Delete leaf node(Node with no children)
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 2. Delete node with one child(Replace with child)
        else if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // 3. Delete node with two children(Replace with inorder successor or inorder predecessor)
        else{
            // Inorder successor(Just Greater than root)
            Node* inorderSuccessor = smallestNodeInRightSubTreeBST(root->right);
            root->data = inorderSuccessor->data;
            root->right = deleteNode(root->right, inorderSuccessor->data);

            // Inorder predecessor(Just Smaller than root)
            // Node* inorderPredecessor = largestNodeInLeftSubTreeBST(root->left);
            // root->data = inorderPredecessor->data;
            // root->left = deleteNode(root->left, inorderPredecessor->data);
        }
    }
    return root;
}

int main(){
    // Create a binary search tree
    BST bst;

    // Insert elements
    bst.root = insertBSTRecursive(bst.root, 10);
    insertBSTRecursive(bst.root, 5);
    insertBSTRecursive(bst.root, 12);
    insertBSTRecursive(bst.root, 2);
    insertBSTRecursive(bst.root, 8);
    insertBSTRecursive(bst.root, 20);
    insertBSTRecursive(bst.root, 1);
    insertBSTRecursive(bst.root, 4);
    insertBSTRecursive(bst.root, 7);
    insertBSTRecursive(bst.root, 15);
    insertBSTRecursive(bst.root, 23);
    insertBSTRecursive(bst.root, 3);
    printLevelOrder(bst.root);
    cout<<endl;

    // Delete elements:
    // 1. Delete leaf node(Node with no children)
    deleteNode(bst.root, 15);
    printLevelOrder(bst.root);
    cout<<endl;
    // 2. Delete node with one child(Replace with child)
    deleteNode(bst.root, 20);
    printLevelOrder(bst.root);
    cout<<endl;
    // 3. Delete node with two children(Replace with inorder successor or inorder predecessor)
    deleteNode(bst.root, 5);
    printLevelOrder(bst.root);
    cout<<endl;

    return 0;
}