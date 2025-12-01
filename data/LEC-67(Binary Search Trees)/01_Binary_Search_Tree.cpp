#include <iostream>
#include <queue>
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

// Binary Search Tree Class:
class BST{
    public:
        Node* root;

        // Constructor
        BST(){
            root = NULL;
        }

        // Insert Function
        void insert(int value){
            insertHelper(root, value);
        }

        // Insert Helper Function
        void insertHelper(Node* currRoot, int value){
            // If root is NULL, then create a new node and make it root
            if (root == NULL){
                root = new Node(value);
            }
            // Else, if value is less than the current node value, then move to left child
            else if (value < currRoot->data){
                // If left child is NULL, then create a new node and make it left child
                if (currRoot->left == NULL){
                    currRoot->left = new Node(value);
                }
                // Else, move to left child
                else{
                    insertHelper(currRoot->left, value);
                }
            }
            // Else, if value is greater than the current node value, then move to right child
            else{
                // If right child is NULL, then create a new node and make it right child
                if (currRoot->right == NULL){
                    currRoot->right = new Node(value);
                }
                // Else, move to right child
                else{
                    insertHelper(currRoot->right, value);
                }
            }
        }

        // Display Function
        void display(){
            display2(root);
            cout<<endl;
        }

        // Display2 Function
        void display2(Node* currRoot){
            // Base condition
            if (currRoot == NULL){
                return;
            }
            // Display left child
            display2(currRoot->left);
            // Display current node
            cout<<currRoot->data<<" ";
            // Display right child
            display2(currRoot->right);
        }

        // Search Function
        Node* search(int value){
            return search2(root, value);
        }

        // Search2 Function
        Node* search2(Node* curr, int value){
            // If value is found or reached the end of the tree
            if (curr == NULL || curr->data == value){
                return curr;
            }
            // If value is less than the current node value, then move to left child
            else if (value < curr->data){
                return search2(curr->left, value);
            }
            // Else, move to right child
            else{
                return search2(curr->right, value);
            }
        }

        // delete Function
        void deleteNode(int value){
            deleteNode2(root, value);
        }

        // deleteNode2 Function
        Node* deleteNode2(Node* curr, int value){
            // Base condition
            if (curr == NULL){
                return curr;
            }
            // If value is less than the current node value, then move to left child
            if (value < curr->data){
                curr->left = deleteNode2(curr->left, value);
            }
            // Else, if value is greater than the current node value, then move to right child
            else if (value > curr->data){
                curr->right = deleteNode2(curr->right, value);
            }
            // Else, if value is equal to the current node value
            else{
                // If current node is a leaf node
                if (curr->left == NULL && curr->right == NULL){
                    delete curr;
                    return NULL;
                }
                // If current node has only one child or no child
                else if (curr->left == NULL){   // as both left and right are NULL condition is defined above, so this condition checks for only right child present or not
                    Node* temp = curr->right;
                    delete curr;
                    return temp;
                }
                else if (curr->right == NULL){
                    Node* temp = curr->left;
                    delete curr;
                    return temp;
                }
                // If current node has two children
                Node* temp = maxValueNodeInLeftSubTree(curr->left);
                curr->data = temp->data;
                curr->left = deleteNode2(curr->left, temp->data);
                // Node* temp = minValueNodeInRightSubTree(curr->right);
                // curr->data = temp->data;
                // curr->right = deleteNode2(curr->right, temp->data);
            }
            return curr;
        }

        // minValueNodeInRightSubTree Function
        Node* minValueNodeInRightSubTree(Node* curr){
            Node* current = curr;
            while (current && current->left != NULL){
                current = current->left;
            }
            return current;
        }
        // maxValueNodeInLeftSubTree Function
        Node* maxValueNodeInLeftSubTree(Node* curr){
            Node* current = curr;
            while (current && current->right != NULL){
                current = current->right;
            }
            return current;
        }
};

// Print BST in Level Order
void printLevelOrder(Node* root){
    // Base condition
    if (root == NULL){
        return;
    }
    // Create a queue
    queue<Node*> q;
    // Push root node to the queue
    q.push(root);
    q.push(NULL);
    // Loop until queue is empty
    while (!q.empty()){
        int nodeInCurrentLevel = q.size();
        // Loop through the current level nodes
        while (nodeInCurrentLevel--){
            // Get the front element of the queue
            Node* node = q.front();
            q.pop();

            if (node != NULL){
                // Display the node data
                cout<<node->data<<" ";
                // If left child is not NULL, then push it to the queue
                if (node->left != NULL){
                    q.push(node->left);
                }
                // If right child is not NULL, then push it to the queue
                if (node->right != NULL){
                    q.push(node->right);
                }
            }
            else{
                cout<<endl;
                if (!q.empty()){
                    q.push(NULL);
                }
            }
        }
    }
    return;
}

int main() {
    // Create a binary search tree:
    BST bst1;

    // Insert elements:
    bst1.insert(4);
    bst1.insert(2);
    bst1.insert(6);
    bst1.insert(5);
    bst1.insert(3);
    bst1.insert(1);
    bst1.insert(7);
    bst1.insert(8);

    // Display elements:
    // bst1.display();
    printLevelOrder(bst1.root);

    // Search elements:
    // if (bst1.search(3) != NULL){
    //     cout<<"Element found"<<endl;
    // }
    // else{
    //     cout<<"Element not found"<<endl;
    // }

    // Delete elements:
    // delete leaf node
    cout<<"Delete leaf node"<<endl;
    bst1.deleteNode(1);
    bst1.display();
    printLevelOrder(bst1.root);
    cout<<endl;
    // delete node with one child
    cout<<"Delete node with one child"<<endl;
    bst1.deleteNode(7);
    bst1.display();
    printLevelOrder(bst1.root);
    cout<<endl;
    // delete node with two children
    cout<<"Delete node with two children"<<endl;
    bst1.deleteNode(4);
    bst1.display();
    printLevelOrder(bst1.root);

    return 0;
}