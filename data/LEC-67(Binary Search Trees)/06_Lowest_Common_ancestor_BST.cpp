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
Node* LCA(Node* root, int n1, int n2){
    if (root == NULL){
        return NULL;
    }

    // If both n1 and n2 are smaller than root, then LCA will lie in left
    if (root->data > n1 && root->data > n2){
        return LCA(root->left, n1, n2);
    }
    // If both n1 and n2 are greater than root, then LCA will lie in right
    else if (root->data < n1 && root->data < n2){
        return LCA(root->right, n1, n2);
    }
    // If one value is smaller and other is greater than root, or one value is equal to root, then root is LCA
    return root;
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

    // we can also create a node and pass the value of node to find LCA
    Node* n1 = new Node(1);
    Node* n2 = new Node(6);

    cout<<"Lowest Common Ancestor of 1 and 6: "<<LCA(bst.root, n1->data, n2->data)->data<<endl;
    cout<<"Lowest Common Ancestor of 1 and 10: "<<LCA(bst.root, 1, 10)->data<<endl;
    cout<<"Lowest Common Ancestor of 3 and 13: "<<LCA(bst.root, 3, 13)->data<<endl;
    cout<<"Lowest Common Ancestor of 4 and 7: "<<LCA(bst.root, 4, 7)->data<<endl;
    cout<<"Lowest Common Ancestor of 4 and 3: "<<LCA(bst.root, 4, 3)->data<<endl;
    return 0;
}

/*
Output:   8
        /   \
       3    10
      / \     \
     1   6    14
        / \   /
       4  7  13
*/