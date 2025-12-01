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

void display(Node* root) {
    cout << root->data << " -> ";
    for(Node* child: root->children) {
        cout << child->data << ", ";
    }
    cout<< endl;

    for(Node* child: root->children) {
        display(child);
    }
}

// Just Greater Node
void justGreaterNode(Node* root, int x, int& ans) {
    if(root == NULL) {
        return;
    }

    // check if root data is greater than x and less than ans
    if(root->data > x && root->data < ans) {
        ans = root->data;
    }

    // recursive call on children
    for(Node* child: root->children) {
        justGreaterNode(child, x, ans);
    }

    return;
}


int main() {
    Node* root = new Node(20);
    Node* n1 = new Node(12);
    Node* n2 = new Node(18);
    Node* n3 = new Node(15);
    Node* n4 = new Node(8);
    Node* n5 = new Node(10);
    Node* n6 = new Node(3);
    Node* n7 = new Node(5);

    root->children.push_back(n1);
    root->children.push_back(n2);
    n1->children.push_back(n3);
    n1->children.push_back(n4);
    n2->children.push_back(n5);  
    n4->children.push_back(n6);
    n4->children.push_back(n7);
    display(root);

    // Just Greater Node
    int x = 10;
    int ans = INT_MAX;

    justGreaterNode(root, x, ans);
    cout << ans << endl;


    return 0;
}