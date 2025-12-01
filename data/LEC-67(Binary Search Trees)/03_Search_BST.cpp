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

// Search Element:
bool searchBST(Node* root, int key){
    // Base case
    if (root == NULL) return false;
    if (root->data == key) return true;

    // Recursive case
    if (root->data > key)
        return searchBST(root->left, key);
    else if(root->data < key) 
        return searchBST(root->right, key);

    return false;
}

int main(){
    // Create a binary search tree
    BST bst;

    // Insert elements
    bst.root = insertBSTRecursive(bst.root, 2);
    insertBSTRecursive(bst.root, 4);
    insertBSTRecursive(bst.root, 6);
    insertBSTRecursive(bst.root, 1);
    insertBSTRecursive(bst.root, 3);
    insertBSTRecursive(bst.root, 5);

    // search element
    if (searchBST(bst.root, 3)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    return 0;
}