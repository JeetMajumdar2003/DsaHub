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
    int rootInorderIdx = inmap[preOrder[preStart]];

    int leftSubTreeSize = rootInorderIdx - inStart;

    // Now call for left and right subtree respectively
    root->left = buildTreeHelper(preOrder, preStart + 1, preStart + leftSubTreeSize, inOrder, inStart, rootInorderIdx - 1, inmap);
    root->right = buildTreeHelper(preOrder, preStart + leftSubTreeSize + 1, preEnd, inOrder, rootInorderIdx + 1, inEnd, inmap);

    return root;
}

Node* buildTree(vector<int>& inOrder, vector<int>& postOrder){
    // 
    unordered_map<int, int> inmap;
    for(int i = 0; i < inOrder.size(); i++){
        inmap[inOrder[i]] = i;
    }

    int inStart = 0;
    int inEnd = inOrder.size() - 1;
    int postStart = 0;
    int postEnd = postOrder.size() - 1;


    Node* root = buildTreeHelper(inOrder, inStart, inEnd, postOrder, postStart, postEnd, inmap);
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
    vector<int> inOrder = {9, 3, 15, 20, 7};
    vector<int> postOrder = {9, 15, 7, 20, 3};

    Node* root = buildTree(inOrder, postOrder);
    printTree(root);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)