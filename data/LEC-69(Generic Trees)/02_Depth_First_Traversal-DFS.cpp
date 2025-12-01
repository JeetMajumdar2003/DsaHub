#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        vector<Node*> children;

    Node(int data) {
        this->data = data;
    }
};

// Preorder Traversal
void preorder(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";  // print the root node
    // recursively call the preorder function for all the children of the root node
    for(Node* child: root->children) {
        preorder(child);
    }
    return;
}

// Inorder Traversal
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    // recursively call the inorder function for the children of the root node, except the last child
    int noOfChildren = root->children.size();
    // recursively call all the children except the last child
    for(int i = 0; i < noOfChildren - 1; i++) {
        inorder(root->children[i]);
    }
    cout << root->data << " ";  // print the root node
    // recursively call the inorder function for the last child if it exists
    if (noOfChildren > 0) {
        inorder(root->children[noOfChildren - 1]);
    }
    return;
}

// Postorder Traversal
void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
    // recursively call the postorder function for all the children of the root node
    for(Node* child: root->children) {
        postorder(child);
    }
    cout << root->data << " ";  // print the root node
    return;
}


int main() {
    Node* root = new Node(10);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);

    root->children.push_back(n1);
    root->children.push_back(n2);
    root->children.push_back(n3);
    n2->children.push_back(n4);
    n4->children.push_back(n5);
    n4->children.push_back(n6);
    n6->children.push_back(n7);
    n6->children.push_back(n8);
    n6->children.push_back(n9);

    preorder(root); // 10 1 2 4 5 6 7 8 9 3
    cout << endl;
    inorder(root);  // 1 2 5 4 7 8 6 9 10 3
    cout << endl;
    postorder(root);    // 1 5 7 8 9 6 4 2 3 10
    return 0;
}

/**
 * 
 * Output:  10 1 2 4 5 6 7 8 9 3
 *          10
 *        / | \
 *       1  2  3
 *           \
 *            4
 *           / \
 *          5   6
 *             /|\
 *            7 8 9
 */