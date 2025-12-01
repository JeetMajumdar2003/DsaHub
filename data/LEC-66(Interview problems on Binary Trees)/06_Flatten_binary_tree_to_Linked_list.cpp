#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// define last node
Node* lastNode = NULL;
void flattenTree(Node* root){
    if(root == NULL) return;

    // Now traverse the tree in reverse preorder
    flattenTree(root->right);
    flattenTree(root->left);

    // Now connect root->right to the last node
    root->right = lastNode;
    root->left = NULL;  // always make left child as NULL
    lastNode = root;    // update the last node with the current node

    return;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flattenTree(root);

    // print the tree only in right child direction
    while(root != NULL) {
        cout << root->data << "->";
        root = root->right;
    }
    cout<< "NULL" << endl;

    return 0;
}