#include <iostream>
#include <vector>
using namespace std;

// Generic Tree Node Class
class Node {
    public:
        int data;
        vector<Node*> children;

    // Constructor
    Node(int data) {
        this->data = data;
    }
};

// Function to print the Generic Tree
void printGenericTree(Node* root) {
    cout << root->data << " -> ";
    for (Node* child : root->children) {
        cout << child->data << ", ";
    }
    cout << endl;
    // Recursive call to children to print their subtrees
    for (Node* child : root->children) {
        printGenericTree(child);
    }
}

int main() {
    // Creating a Generic Tree
    Node* root = new Node(10);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);

    // Connecting the nodes
    root->children.push_back(n1);
    root->children.push_back(n2);
    n2->children.push_back(n3);
    n2->children.push_back(n4);
    n2->children.push_back(n5);

    // Printing the data of the nodes
    printGenericTree(root);
    return 0;
}