#include <iostream>
#include<vector>
#include <unordered_map>
#include <queue>
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

Node* buildTreeHelper(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd, unordered_map<int, int>& inmap){
    if(preStart > preEnd || inStart > inEnd){
        return NULL;    // handaling the leaf nodes
    }
    
    Node* root = new Node(preOrder[preStart]);
    // This snippet acts as the base case for the recursion. It stops the recursion when we reach a leaf node, preventing infinite recursion.
    if(preStart == preEnd){
        return root;
    }

    int rootInorderIdx = inmap[preOrder[preStart]];

    int leftSubTreeSize = rootInorderIdx - inStart;

    // Now call for left and right subtree respectively
    root->left = buildTreeHelper(preOrder, preStart + 1, preStart + leftSubTreeSize, inOrder, inStart, rootInorderIdx - 1, inmap);
    root->right = buildTreeHelper(preOrder, preStart + leftSubTreeSize + 1, preEnd, inOrder, rootInorderIdx + 1, inEnd, inmap);

    return root;
}

Node* buildTree(vector<int>& preOrder, vector<int>& inOrder){
    // 
    unordered_map<int, int> inmap;
    for(int i = 0; i < inOrder.size(); i++){
        inmap[inOrder[i]] = i;
    }

    int preStart = 0;
    int preEnd = preOrder.size() - 1;
    int inStart = 0;
    int inEnd = inOrder.size() - 1;


    Node* root = buildTreeHelper(preOrder, preStart, preEnd, inOrder, inStart, inEnd, inmap);
    return root;
}

// print in level order:
void printTree(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        int nodesAtCurrentLevel = q.size(); // Number of nodes at the current level
        while(nodesAtCurrentLevel--){
            // Get the front element of the queue
            Node* currentNode = q.front();
            // Print the front element
            cout << currentNode->data << " ";
            // Pop the front element
            q.pop();

            // If the left child exists, push it into the queue
            if (currentNode->left) q.push(currentNode->left);
            // If the right child exists, push it into the queue
            if (currentNode->right) q.push(currentNode->right);
        }
        cout << endl;
    }
}



int main() {
    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inOrder = {9, 3, 15, 20, 7};

    Node* root = buildTree(preOrder, inOrder);
    printTree(root);

    return 0;
}