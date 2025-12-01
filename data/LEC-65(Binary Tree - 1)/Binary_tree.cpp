#include <iostream>
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

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    // Print the root, left and right child
    cout<<"Root: "<<root->data<<endl;
    cout<<"Left Child: "<<root->left->data<<endl;
    cout<<"Right Child: "<<root->right->data<<endl;
    return 0;
}