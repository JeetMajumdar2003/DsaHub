#include<iostream>
#include<vector>
using namespace std;

class Node {
    int data;
public:
    Node(int value) : data(value) {}
    int getData() const { return data; }
};

class Edge {
    Node* source;
    Node* destination;
    int weight;
    bool directed;    
public:
    Edge(Node* src, Node* dest, int w, bool dir) : source(src), destination(dest), weight(w), directed(dir) {}
    Node* getSource() const { return source; }
    Node* getDestination() const { return destination; }
    int getWeight() const { return weight; }
    bool isDirected() const { return directed; }
};

class Graph {
    vector<Node*> nodes;
    vector<Edge*> edges;
public:
    void addNode(int value) {
        nodes.push_back(new Node(value));
    }

    void addEdge(int src, int dest, int weight, bool directed) {
        Node* source = nullptr;
        Node* destination = nullptr;

        for (auto node : nodes) {
            if (node->getData() == src) source = node;
            if (node->getData() == dest) destination = node;
        }

        if (source && destination) {
            edges.push_back(new Edge(source, destination, weight, directed));
        }
    }

    vector<Edge*> getEdges() const {
        return edges;
    }
};

int main() {
    Graph g;
    g.addNode(1);
    g.addNode(2);
    g.addEdge(1, 2, 5, false);

    // print
    for (const auto& edge : g.getEdges()) {
        cout << "Edge from " << edge->getSource()->getData()
             << " to " << edge->getDestination()->getData()
             << " with weight " << edge->getWeight()
             << (edge->isDirected() ? " (directed)" : " (undirected)") << endl;
    }

    return 0;
}