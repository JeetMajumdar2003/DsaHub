#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int data;
        vector<Node*> children;

    Node(int data) {
        this->data = data;
    }
};

// Serialize Tree
void serializedTreeFunction(Node* root, string& serializedString) {
    if(root == NULL) {
        return;
    }

    // Serialize the tree
    serializedString += to_string(root->data) + ":" + to_string(root->children.size()) + ":";
    for(Node* child: root->children) {
        serializedString += to_string(child->data) + ",";
    }
    serializedString.pop_back();
    // serializedString.pop_back();
    serializedString += "\n";

    // Recursive call on children
    for(Node* child: root->children) {
        serializedTreeFunction(child, serializedString);
    }
    return;
}


// Deserialize Tree Helper Function: This function will construct the tree from the created map
Node* deserializeTreeHelper(unordered_map<int, string>& map, int rootNodeData) {
    // Create the root node with rootNodeData(eg. 100)
    Node* root = new Node(rootNodeData);

    // Extract the children string
    string childrenString = map[rootNodeData];  // Extract the children string(eg. 3:10,20,30)
    // cout << "Processing node: " << rootNodeData << " with children string: " << childrenString << endl;
    
    // Extract the number of children
    int colon2 = childrenString.find(":");
    int numberOfChildren = stoi(childrenString.substr(0, colon2)); // Extract the number of children(eg. 3)
    // cout << "Number of children: " << numberOfChildren << endl;
    // check if the node has no children(eg. leaf node)
    if(numberOfChildren == 0) {
        return root;
    }

    // Extract the children data(eg. 10,20,30)
    string childrenDataString = childrenString.substr(colon2+1);
    // cout << "Children data string: " << childrenDataString << endl;

    // Split the children data by ',' and recursively call on children
    int start = 0;
    for(int i=0; i<numberOfChildren; i++) {

        int end = childrenDataString.find(",", start); // Find the end index of the child data
        if(end == string::npos) end = childrenDataString.size();  // If the end index is not found, then it is the last child data
        int childData = stoi(childrenDataString.substr(start, end)); // Extract the child data(eg. 10)
        // cout << "Child data: " << childData << endl;
        root->children.push_back(deserializeTreeHelper(map, childData)); // Recursive call on children
        start = end+1;    // Update the start index for next child(eg. 20)

        // if(childrenDataString[i] == ',') {
        //     int childData = stoi(childrenDataString.substr(start, i-start)); // Extract the child data(eg. 10)
        //     root->children.push_back(deserializeTreeHelper(map, childData)); // Recursive call on children
        //     start = i+1;    // Update the start index for next child(eg. 20)
        // }
    }
    // // Extract the last child data
    // int childData = stoi(childrenDataString.substr(start)); // Extract the child data(eg. 30)
    // root->children.push_back(deserializeTreeHelper(map, childData)); // Recursive call on children

    return root;
}

// Deserialize Tree
Node* deserializeTreeFunction(string serializedString) {
    if(serializedString.size() == 0) {
        return NULL;
    }

    // Split the serializedString by '\n'
    unordered_map<int, string> map;
    int start = 0;
    for(int i=0; i<serializedString.size(); i++) {
        if(serializedString[i] == '\n') {
            string currentNodeString = serializedString.substr(start, i-start); // Extract the current node string(eg. 100:3:10,20,30)
            int colon1 = currentNodeString.find(":");
            int nodeData = stoi(currentNodeString.substr(0, colon1)); // Extract the node data(eg. 100)
            map[nodeData] = currentNodeString.substr(colon1+1); // Extract the children string(eg. 3:10,20,30)

            start = i+1;    // Update the start index for next node(eg. 10:0)
        }
    }

    // Extract the root node data
    int rootNodeData = stoi(serializedString.substr(0, serializedString.find(":"))); // Extract the root node data(eg. 100)

    // Construct the tree
    return deserializeTreeHelper(map, rootNodeData);
}

// Level Order Traversal
void levelOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> queue;
    queue.push(root);

    while(!queue.empty()) {
        int size = queue.size();
        while(size--) {
            Node* curr = queue.front();
            queue.pop();
            cout << curr->data << " ";
            for(Node* child: curr->children) {
                queue.push(child);
            }
        }
        cout << endl;
    }
}

int main() {
    Node* root = new Node(100);
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    Node* n5 = new Node(50);
    Node* n6 = new Node(60);
    Node* n7 = new Node(70);
    Node* n8 = new Node(80);
    Node* n9 = new Node(90);

    root->children.push_back(n1);
    root->children.push_back(n2);
    root->children.push_back(n3);
    n2->children.push_back(n4);
    n4->children.push_back(n5);
    n4->children.push_back(n6);
    n6->children.push_back(n7);
    n6->children.push_back(n8);
    n6->children.push_back(n9);

    string serializedString = "";
    serializedTreeFunction(root, serializedString);
    cout << serializedString << endl;

    Node* deserializedRoot = deserializeTreeFunction(serializedString);

    levelOrder(deserializedRoot);

    return 0;
}

/** Output: 
100:3:10,20,30
10:0
20:1:40
40:2:50,60
50:0
60:3:70,80,90
70:0
80:0
90:0
30:0
 */

/**
 *         100
 *        / | \
 *      10 20 30
 *           \
 *           40
 *          / \
 *         50  60
 *            / | \
 *          70  80 90
 */