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

// Inorder Predecessor and Successor in BST:
void inorderPreSuccBST(Node* root, Node* &pre, Node* &succ, int key){
    if(root == NULL){
        return;
    }

    // If key is the root node
    if(root->data == key){
        // Predecessor: Maximum right most value in left subtree
        if(root->left != NULL){
            Node* temp = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            pre = temp;
        }

        // Successor: Minimum left most value in right subtree
        if(root->right != NULL){
            Node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }

    // If key is smaller than root, then key lies in left subtree
    if(root->data > key){
        succ = root;
        inorderPreSuccBST(root->left, pre, succ, key);
    }
    // If key is greater than root, then key lies in right subtree
    else if(root->data < key){
        pre = root;
        inorderPreSuccBST(root->right, pre, succ, key);
    }
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
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
    cout<<endl;

    // Inorder Predecessor and Successor:
    Node* pre = NULL;
    Node* succ = NULL;
    int key = 8;
    inorderPreSuccBST(bst.root, pre, succ, key);

    if(pre != NULL){
        cout<<"Predecessor of "<<key<<": "<<pre->data<<endl;
    }
    else{
        cout<<"Predecessor of "<<key<<": NULL"<<endl;
    }
    if(succ != NULL){
        cout<<"Successor of "<<key<<": "<<succ->data<<endl;
    }
    else{
        cout<<"Successor of "<<key<<": NULL"<<endl;
    }
    
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