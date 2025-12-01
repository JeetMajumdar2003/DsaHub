#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
    public:
        int data;
        vector<Node*> children;

    Node(int data) {
        this->data = data;
    }
};

// Level Order Traversal
void levelOrder(Node* root){
    if(root == NULL) {
        return;
    }

    // Create a queue and push the root node into it
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int noOfChildrenInCurrentLevel = q.size();
        while(noOfChildrenInCurrentLevel--) {
            // Remove the front element from the queue
            Node* current = q.front();
            q.pop();
            // Print the front element
            cout << current->data << " ";
            // Add all the children of the front element to the queue
            for(Node* child : current->children) {
                q.push(child);
            }
        }
        cout << endl;
    }
}

// Mirror Tree: Reverse the children of each node
void mirrorTree(Node* root) {
    if(root == NULL) {
        return;
    }

    // Reverse the children of the root node
    reverse(root->children.begin(), root->children.end());

    // Recursive call on children
    for(Node* child: root->children) {
        mirrorTree(child);
    }
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

    levelOrder(root); // 10 1 2 4 5 6 7 8 9 3
    cout << endl;

    mirrorTree(root);

    levelOrder(root); // 10 3 9 8 7 6 5 4 2 1

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