#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;

// Graph Implementation: Add Edge
void add_edge(int src, int dest, vector<list<int>> &graph, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

void dfs(int curr, unordered_set<int> &visited){
    visited.insert(curr);    // Mark the current node as visited

    // Explore all neighbors
    for (int neighbor : graph[curr]) {
        // If the neighbor has not been visited, continue DFS
        if (!visited.count(neighbor)) {
            dfs(neighbor, visited);
        }
    }
}

int connected_components() {
    int count = 0;
    // Iterate through all nodes in the graph and perform DFS if not visited
    for (int i = 0; i < graph.size(); i++) {
        if (!visited.count(i)) { // If the node has not been visited
            dfs(i, visited); // Perform DFS from this node
            count++; // Increment the count of connected components
        }
    }
    return count;
}

int main() {
    int v = 7;
    graph.resize(v);
    visited.clear();

    add_edge(0, 1, graph);
    add_edge(0, 4, graph);
    // add_edge(1, 5, graph);
    add_edge(1, 3, graph);
    add_edge(2, 5, graph);
    add_edge(2, 6, graph);
    add_edge(3, 4, graph);
    add_edge(5, 6, graph);

    int connectedComponents = connected_components();
    cout << "Number of connected components: " << connectedComponents << endl;

    return 0;
}

/*
    0-----1-----5
    |     |    / \
    |     |   /   \
    4-----3  6-----2
*/