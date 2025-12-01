#include <iostream>
#include <vector>
#include <functional>   // this header file is used for lambda functions
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Generate all BSTs with nodes 1 to n
vector<Node*> generateBSTs(int start, int end) {
    // Base case
    vector<Node*> treesList;
    if (start > end) {
        treesList.push_back(NULL);
        return treesList;
    }
    // Recursive case
    for (int i = start; i <= end; i++) {
        // Generate all left subtrees
        vector<Node*> LeftSubtrees = generateBSTs(start, i - 1);
        // Generate all right subtrees
        vector<Node*> RightSubtrees = generateBSTs(i + 1, end);
        // Connect left and right subtrees to the root(i)
        for (Node* leftsubtree : LeftSubtrees) {
            for (Node* rightsubtree : RightSubtrees) {
                Node* root = new Node(i);
                root->left = leftsubtree;
                root->right = rightsubtree;
                treesList.push_back(root);
            }
        }
    }
    return treesList;
}

int main() {
    // Generate all BSTs with nodes 1 to n
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<Node*> BSTs = generateBSTs(1, n);

    // Number of BSTs
    cout << "Number of BSTs with nodes 1 to " << n << " are: " << BSTs.size() << endl;

    cout << "All BSTs with nodes 1 to " << n << " are: " << endl;

    // Print all BSTs
    for (Node* root : BSTs) {
        cout << "Inorder Traversal: ";
        // Preorder Traversal
        function<void(Node*)> preorder = [&](Node* root) {
            if (root == NULL) {
                return;
            }
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        };
        preorder(root);
        cout << endl;
    }
    return 0;
}