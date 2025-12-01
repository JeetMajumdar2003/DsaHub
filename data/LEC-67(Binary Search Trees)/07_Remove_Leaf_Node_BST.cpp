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

// Lowest Common Ancestor in BST:
Node* removeLeafNodeBST(Node* root){
    if(root == NULL){
        return NULL;
    }

    // if root is leaf node
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }

    // if root is not leaf node, then check for left and right child
    root->left = removeLeafNodeBST(root->left);
    root->right = removeLeafNodeBST(root->right);

    return root;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    printInorder(root->left);
    printInorder(root->right);
}

int main(){
    // Create a binary search tree
    BST bst;
    bst.root = insertBSTRecursive(bst.root, 8);
    insertBSTRecursive(bst.root, 3);
    insertBSTRecursive(bst.root, 10);
    insertBSTRecursive(bst.root, 1);
    insertBSTRecursive(bst.root, 6);
    insertBSTRecursive(bst.root, 14);
    insertBSTRecursive(bst.root, 4);
    insertBSTRecursive(bst.root, 7);
    insertBSTRecursive(bst.root, 13);
    printInorder(bst.root);
    cout << endl;

    // remove leaf nodes from BST
    bst.root = removeLeafNodeBST(bst.root);

    // print inorder traversal of BST
    printInorder(bst.root);
    
    return 0;
}

/*
Input:   8
        /   \
       3    10
      / \     \
     1   6    14
        / \   /
       4  7  13
*/