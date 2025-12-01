#include <iostream>
#include <unordered_map>
#include <queue>
#include <unordered_set>
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

// calculate time to infect all nodes
int calculateTime(Node* startNode, unordered_map<Node*, Node*>& parentMap){

    // infected set to store infected nodes
    unordered_set<Node*> infected;
    infected.insert(startNode);

    int time = 0;

    queue<Node*> q;
    q.push(startNode);
    while (!q.empty()){
        int currentLevelNodes = q.size();
        bool isInfected = false;
        while(currentLevelNodes--){
            Node* current = q.front();
            q.pop();

            // check if left node is not infected then infect it
            if(current->left != NULL && infected.find(current->left) == infected.end()){
                q.push(current->left);
                infected.insert(current->left);
                isInfected = true;
            }

            // check if right node is not infected then infect it
            if(current->right != NULL && infected.find(current->right) == infected.end()){
                q.push(current->right);
                infected.insert(current->right);
                isInfected = true;
            }

            // check if parent node is not infected then infect it
            if(parentMap[current] != NULL && infected.find(parentMap[current]) == infected.end()){
                q.push(parentMap[current]);
                infected.insert(parentMap[current]);
                isInfected = true;
            }
        }

        if(isInfected){
            time++;
        }
    }

    return time;
}

// find the infected node position and make parentMap
Node* findInfectedANDmakeParent(Node* root, unordered_map<Node*, Node*>& parentMap, int target){
    queue<Node*> q;
    q.push(root);

    Node* startNode = NULL;
    while (!q.empty()){
        Node* current = q.front();
        q.pop();

        if(current->data == target){
            startNode = current;
        }

        if(current->left){
            parentMap[current->left] = current;
            q.push(current->left);
        }

        if(current->right){
            parentMap[current->right] = current;
            q.push(current->right);
        }
    }

    return startNode;
}

int amountOfTime(Node* root, int target){
    unordered_map<Node*, Node*> parentMap;  // map to store parent of each node(child -> parent)

    // find the infected(target) node position and make parentMap
    Node* startNode = findInfectedANDmakeParent(root, parentMap, target);

    // calculate time to infect all nodes
    return calculateTime(startNode, parentMap);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(2);
    root->right->left = new Node(10);
    root->right->right = new Node(6);

    cout << amountOfTime(root, 3) << endl;

    return 0;
}