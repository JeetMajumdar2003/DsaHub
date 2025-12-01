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

Node* buildTreeHelper(vector<int>& preOrder, int preStart, int preEnd, vector<int>& postOrder, int postStart, int postEnd, unordered_map<int, int>& postmap){
    if(preStart > preEnd || postStart > postEnd){
        return NULL;    // handaling the leaf nodes
    }
    
    Node* root = new Node(preOrder[preStart]);
    // This snippet acts as the base case for the recursion. It stops the recursion when we reach a leaf node, preventing infinite recursion.
    if(preStart == preEnd){
        return root;
    }


    int leftChildPostOrderIdx = postmap[preOrder[preStart + 1]];

    /** Finding leftChildIdx in postOrder vector
    int leftChildPostOrderIdx = -1;
    for (int i = postStart; i < postEnd; i++) {
        if (postOrder[i] == preOrder[preStart + 1]) {
            leftChildPostOrderIdx = i;
            cout << "leftChildPostOrderIdx: " << preOrder[preStart + 1] << endl;
            break;
        }
    }
     */

    int leftSubTreeSize = leftChildPostOrderIdx - postStart + 1;

    // Now call for left and right subtree respectively
    root->left = buildTreeHelper(preOrder, preStart + 1, preStart + leftSubTreeSize, postOrder, postStart, leftChildPostOrderIdx, postmap);
    root->right = buildTreeHelper(preOrder, preStart + leftSubTreeSize + 1, preEnd, postOrder, leftChildPostOrderIdx + 1, postEnd - 1, postmap);

    return root;
}

Node* buildTree(vector<int>& preOrder, vector<int>& postOrder){
    // Creating a map to store the indices of elements in postOrder
    unordered_map<int, int> postmap;
    for(int i = 0; i < postOrder.size(); i++){
        postmap[postOrder[i]] = i;
    }

    int preStart = 0;
    int preEnd = preOrder.size() - 1;
    int postStart = 0;
    int postEnd = postOrder.size() - 1;


    Node* root = buildTreeHelper(preOrder, preStart, preEnd, postOrder, postStart, postEnd, postmap);
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
    vector<int> preOrder = {10, 20, 40, 50, 30, 60, 70};
    vector<int> postOrder = {40, 50, 20, 60, 70, 30, 10};

    Node* root = buildTree(preOrder, postOrder);
    printTree(root);

    return 0;
}