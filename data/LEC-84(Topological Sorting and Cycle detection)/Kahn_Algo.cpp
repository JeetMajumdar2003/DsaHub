#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

// Internal graph representation uses compact indices.
// External node labels (any int) are mapped to these indices.
vector<vector<int>> graph;
unordered_map<int,int> label_to_index;
vector<int> index_to_label;

// Ensure label exists in mapping; returns internal index.
int get_index_for_label(int label) {
    auto it = label_to_index.find(label);
    if (it != label_to_index.end()) return it->second;
    int new_index = static_cast<int>(graph.size());
    label_to_index[label] = new_index;
    index_to_label.push_back(label);
    graph.emplace_back(); // add adjacency list for new node
    return new_index;
}

// Graph Implementation: Add Edge (directed by default)
void add_edge(int src_label, int dest_label, bool bi_dir = false) {
    int src = get_index_for_label(src_label);
    int dest = get_index_for_label(dest_label);
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

// Topological Sort using Kahn's Algorithm
void kahn_topological_sort() {
    int n = static_cast<int>(graph.size());
    if (n == 0) {
        cout << "Graph is empty\n";
        return;
    }

    // Calculate in-degree
    vector<int> in_degree(n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            if (v >= 0 && v < n) in_degree[v]++;
        }
    }

    // Find all nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    if (q.empty()) {
        cout << "No nodes with zero in-degree found (graph may have a cycle)\n";
    } else {
        cout << "Nodes with zero in-degree (labels):";
        queue<int> tmp = q;
        while (!tmp.empty()) {
            cout << " " << index_to_label[tmp.front()];
            tmp.pop();
        }
        cout << "\n";
    }

    // Process nodes with zero in-degree
    int processed = 0;
    cout << "Processing order (labels):\n";
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << index_to_label[node] << "\n";
        ++processed;
        for (int neighbor : graph[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (processed != n) {
        cout << "Cycle detected or graph has nodes that couldn't be processed (processed "
             << processed << " of " << n << ")\n";
    } else {
        cout << "Topological sort processed all " << n << " nodes.\n";
    }
}

int main() {
    // No fixed n; nodes are added on demand via add_edge calls.
    // Example edges (same as your original):
    add_edge(6, 9);
    add_edge(1, 9);
    add_edge(1, 3);
    add_edge(9, 3);
    add_edge(9, 8);
    add_edge(9, 5);
    add_edge(9, 0);
    add_edge(3, 5);
    add_edge(8, 0);
    add_edge(5, 0);
    add_edge(0, 7);

    kahn_topological_sort();

    return 0;
}