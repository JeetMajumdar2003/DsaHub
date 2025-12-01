#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

/* down view of the binary tree
void downView(Node* root){
    // Base case
    if(root == NULL){
        return;
    }

    // Print the left side of the tree
    Node* temp = root;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->left;
    }

    // Print the right side of the tree
    temp = root->right;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->right;
    }
}
*/

// Down view of the binary tree
vector<int> downViewBinaryTree(Node* root){
    vector<int> result;
    // Base case
    if(root == NULL){
        return result;
    }

    // Create a queue to store the node and its horizontal distance(column)
    queue<pair<Node*, int>> q;
    // Create a map to store the horizontal distance(column) and the node value
    map<int, int> m; // map<column, value>

    // Push the root node and its horizontal distance(column) into the queue
    q.push(make_pair(root, 0));  // or q.push({root, 0}); // root node has column 0

    // Level order traversal of the binary tree
    while(!q.empty()){
        
        int nodeAtCurrentLevel = q.size();
        while(nodeAtCurrentLevel--){
            // Get the front element of the queue
            pair<Node*, int> temp = q.front();
            // Get the node and its horizontal distance(column)
            Node* currNode = temp.first;
            int currColumn = temp.second;
            q.pop();

            // Update the map with the last node value of that column
            m[currColumn] = currNode->data; // it will store the last node value of that column means it will update the value of that column in the map with the last node value of that column

            // If the left child is present, then push it into the queue and update the column value (column - 1)
            if(currNode->left != NULL){
                q.push(make_pair(currNode->left, currColumn - 1));
            }
            // If the right child is present, then push it into the queue and update the column value (column + 1)
            if(currNode->right != NULL){
                q.push(make_pair(currNode->right, currColumn + 1));
            }
        }
    }
    // Traverse the map and store the values in the result vector
    for(auto i : m){
        result.push_back(i.second);
    }

    return result;
}

int main() {
    // Create a binary tree
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->left = new Node(9);
    root->right->right = new Node(11);

    // Down view of the binary tree
    vector<int> result = downViewBinaryTree(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}

/**
 * Tree:
 *         2
 *       /   \
 *      4     10
 *     / \   /  \
 *    6   5 9    11
 * 
 *        \^/
 * Output: 6 4 5 10 11 or 6 4 5 9 11
 */