/** Fibonacci Heap Implementation in C++:
 * Specialized heap data structure consisting of a collection of trees that satisfies the minimum-heap property.
 * Supports a variety of operations including insertion, finding the minimum, extracting the minimum, and decreasing a key.
 * 
 * Time Complexity:
 * 1. Insertion: O(1) amortized time.
 * 2. Find Minimum: O(1) time.
 * 3. Extract Minimum: O(log n) amortized time.
 * 4. Decrease Key: O(1) amortized time.
 * 5. Delete: O(log n) amortized time.
 * Space Complexity: O(n) where n is the number of nodes in the heap.
 * 
 * Implementation Steps:
 * 1. Create an instance of the FibonacciHeap class.
 * 2. Use the insert method to add elements to the heap.
 * 3. Use getMin to retrieve the minimum element.
 * 4. Use extractMin to remove and return the minimum element.
 * 5. Use isEmpty to check if the heap is empty.
 * 
 * Usage:
 * 1. Used in network optimization algorithms like Dijkstra's and Prim's algorithms.
 * 2. Efficient priority queue operations in various applications.
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * Node structure for Fibonacci Heap
 *   key: Value of the node
 *   degree: Number of children
 *   parent: Pointer to the parent node
 *   child: Pointer to one of the child nodes
 *   left, right: Pointers to the left and right siblings
 *   mark: Boolean flag for decrease key operation
*/
struct Node {
    int key;
    int degree;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    bool mark;

    Node(int value) {
        key = value;
        degree = 0;
        parent = child = nullptr;
        left = right = this;
        mark = false;
    }
};

// Fibonacci Heap class
class FibonacciHeap {
private:
    Node* minNode;
    int nodeCount;

    void linkNodes(Node* y, Node* x) {
        y->left->right = y->right;
        y->right->left = y->left;

        y->parent = x;
        if (x->child == nullptr) {
            x->child = y;
            y->left = y->right = y;
        } else {
            y->left = x->child;
            y->right = x->child->right;
            x->child->right->left = y;
            x->child->right = y;
        }
        x->degree++;
        y->mark = false;
    }

    void consolidate() {
        int maxDegree = log2(nodeCount) + 1;
        vector<Node*> degreeTable(maxDegree, nullptr);

        vector<Node*> rootNodes;
        Node* current = minNode;
        do {
            rootNodes.push_back(current);
            current = current->right;
        } while (current != minNode);

        for (Node* node : rootNodes) {
            int degree = node->degree;
            while (degreeTable[degree] != nullptr) {
                Node* other = degreeTable[degree];
                if (node->key > other->key) swap(node, other);
                linkNodes(other, node);
                degreeTable[degree] = nullptr;
                degree++;
            }
            degreeTable[degree] = node;
        }

        minNode = nullptr;
        for (Node* node : degreeTable) {
            if (node != nullptr) {
                if (minNode == nullptr || node->key < minNode->key) {
                    minNode = node;
                }
            }
        }
    }

public:
    FibonacciHeap() : minNode(nullptr), nodeCount(0) {}

    void insert(int key) {
        Node* newNode = new Node(key);
        if (minNode == nullptr) {
            minNode = newNode;
        } else {
            newNode->left = minNode;
            newNode->right = minNode->right;
            minNode->right->left = newNode;
            minNode->right = newNode;
            if (key < minNode->key) {
                minNode = newNode;
            }
        }
        nodeCount++;
    }

    int getMin() {
        if (minNode == nullptr) {
            throw runtime_error("Heap is empty");
        }
        return minNode->key;
    }

    int extractMin() {
        if (minNode == nullptr) {
            throw runtime_error("Heap is empty");
        }

        Node* oldMin = minNode;
        if (oldMin->child != nullptr) {
            Node* child = oldMin->child;
            do {
                child->parent = nullptr;
                child = child->right;
            } while (child != oldMin->child);

            Node* minLeft = minNode->left;
            Node* childLeft = oldMin->child->left;

            minLeft->right = oldMin->child;
            oldMin->child->left = minLeft;

            childLeft->right = minNode;
            minNode->left = childLeft;
        }

        oldMin->left->right = oldMin->right;
        oldMin->right->left = oldMin->left;

        if (oldMin == oldMin->right) {
            minNode = nullptr;
        } else {
            minNode = oldMin->right;
            consolidate();
        }

        nodeCount--;
        int minValue = oldMin->key;
        delete oldMin;
        return minValue;
    }

    bool isEmpty() {
        return minNode == nullptr;
    }
};

int main() {
    FibonacciHeap heap;

    heap.insert(10);
    heap.insert(2);
    heap.insert(15);
    heap.insert(6);

    cout << "Minimum: " << heap.getMin() << endl;

    cout << "Extracted Min: " << heap.extractMin() << endl;
    cout << "New Minimum: " << heap.getMin() << endl;
    return 0;
}