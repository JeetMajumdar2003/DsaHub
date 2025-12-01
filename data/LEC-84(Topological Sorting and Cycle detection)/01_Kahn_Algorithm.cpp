#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;

// Graph Implementation: Add Edge
void add_edge(int src, int dest, bool bi_dir = false) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

// Topological Sort using Kahn's Algorithm
void kahn_topological_sort() {
    // Calculate in-degree
    vector<int> in_degree(graph.size(), 0);
    for (const auto& neighbors : graph) {
        for (int neighbor : neighbors) {
            in_degree[neighbor]++;
        }
    }

    // Kahn's algorithm: Find all nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < in_degree.size(); i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            visited.insert(i);
        }
    }

    cout << "Topological Sort using Kahn's Algorithm: ";
    // Process nodes with zero in-degree
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Decrease in-degree of neighbors
        for (int neighbor : graph[node]) {
            if(!visited.count(neighbor)) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
    cout << endl;
}

// Cycle Detection
bool has_cycle() {
    // If we visited all nodes, no cycle exists
    return visited.size() != graph.size();
}

int main() {
    int n = 8;
    graph.resize(n);
    visited.reserve(n);
    add_edge(0, 2);
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    add_edge(2, 4);
    add_edge(2, 5);
    add_edge(2, 6);     // For Cycle Detection use add_edge(6, 2);
    add_edge(3, 5);
    add_edge(4, 6);
    add_edge(5, 6);
    add_edge(6, 7);

    kahn_topological_sort();

    cout << "Cycle Detected: " << (has_cycle() ? "Yes" : "No") << endl;

    return 0;
}