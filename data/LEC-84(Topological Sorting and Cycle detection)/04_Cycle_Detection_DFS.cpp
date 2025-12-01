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

bool dfs(int curr, int parent){
    visited.insert(curr);    // Mark the current node as visited

    // Explore all neighbors
    for (int neighbor : graph[curr]) {
        // If the neighbour is already visited and it is not the parent, cycle detected
        if (visited.count(neighbor) and neighbor != parent) {
            // Cycle detected
            return true;
        }
        // If the neighbor has not been visited, continue DFS
        if (!visited.count(neighbor)) {
            return dfs(neighbor, curr);
        }
    }

    // If no cycle found
    return false;
}

bool hasCycle() {
    visited.clear();
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited.count(i)) {
            if (dfs(i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int v = 7;
    graph.resize(v);
    visited.clear();

    add_edge(0, 1, graph);
    add_edge(0, 4, graph);
    add_edge(1, 5, graph);
    // add_edge(1, 3, graph);
    add_edge(2, 6, graph);
    add_edge(3, 4, graph);
    add_edge(5, 6, graph);


    cout << (hasCycle() ? "Cycle detected" : "No cycle found") << endl;

    return 0;
}

/*
    0-----1-----5
    |     |    /
    |     |   /
    4-----3  6-----2
*/