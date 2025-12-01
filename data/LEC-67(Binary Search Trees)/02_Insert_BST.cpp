#include <iostream>
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

// Insert Elements:
void insertBST(Node* &root, int value){
    Node *newNode = new Node(value);
    if (root == NULL){
        root = newNode;
        return;
    }

    Node* current = root;
    while (1){
        if (current->data > value){
            if (current->left == NULL){
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        else{
            if (current->right == NULL){
                current->right = newNode;
                return;
            }
            current = current->right;
        }
    }
    return;
}

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

// Print Inorder: (Sorted Order)
void printInorder(Node *root){
    if (root == NULL){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
    return;
}

int main(){
    // Create a binary search tree
    BST bst;

    // Insert elements
    // insertBST(bst.root, 5);
    // insertBST(bst.root, 3);
    // insertBST(bst.root, 7);
    bst.root = insertBSTRecursive(bst.root, 2);
    insertBSTRecursive(bst.root, 4);
    insertBSTRecursive(bst.root, 6);


    // Print Inorder
    printInorder(bst.root);

    return 0;
}