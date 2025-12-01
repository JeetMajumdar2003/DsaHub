#include <iostream>
#include <vector>
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

// M-1: Check if the binary tree is a BST
bool checkBSTHelper(Node* root, long min, long max){
    if(root == NULL){
        return true;
    }

    // 1. Check if the root node value is within the range
    bool isBST = (root->data > min && root->data < max);

    // 2. Check if the left and right subtrees are BST
    bool leftBST = checkBSTHelper(root->left, min, root->data);
    bool rightBST = checkBSTHelper(root->right, root->data, max);

    return (isBST && leftBST && rightBST);
}

bool checkBST(Node* root){
    return checkBSTHelper(root, LONG_MIN, LONG_MAX);
}

// M-2: Using Inorder Traversal: Check if the inorder traversal of the binary tree is sorted
bool checkBSTInorder(Node* root, int &prev){
    if(root == NULL){
        return true;
    }

    // Check if the left subtree is BST: call for left subtree
    if(!checkBSTInorder(root->left, prev)){
        return false;
    }

    // Check if the current node is greater than the previous node: check for current node
    if(root->data <= prev){
        return false;
    }
    prev = root->data;

    // Check if the right subtree is BST: call for right subtree
    return checkBSTInorder(root->right, prev);
}

// M-3: Using Inorder Traversal: Store the inorder traversal in a vector and check if it is sorted
vector<int> inorder;

// inorder traversal of the binary tree
void inorderVector(Node* &root, vector<int> &inorder){
    if(root == NULL){
        return;
    }

    inorderVector(root->left, inorder);
    inorder.push_back(root->data);
    inorderVector(root->right, inorder);
}

int main() {
    // Create a binary tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(6);

    // M-1: Check if the tree is a BST
    if(checkBST(root)){
        cout<<"The binary tree is a BST."<<endl;
    }else{
        cout<<"The binary tree is not a BST."<<endl;
    }

    // M-2: Check if the tree is a BST using inorder traversal
    int prev = INT_MIN;
    if(checkBSTInorder(root, prev)){
        cout<<"The binary tree is a BST."<<endl;
    }else{
        cout<<"The binary tree is not a BST."<<endl;
    }

    // M-3: Check if the tree is a BST using inorder traversal and storing the inorder traversal in a vector
    inorderVector(root, inorder);
    for(int i=0; i<inorder.size(); i++){
        cout<<inorder[i]<<" ";
    }
    cout<<endl;

    // Check if the inorder traversal is sorted
    bool isBST = true;
    for(int i=1; i<inorder.size(); i++){
        if(inorder[i] <= inorder[i-1]){
            isBST = false;
            break;
        }
    }

    if(isBST){
        cout<<"The binary tree is a BST."<<endl;
    }else{
        cout<<"The binary tree is not a BST."<<endl;
    }
    return 0;
}