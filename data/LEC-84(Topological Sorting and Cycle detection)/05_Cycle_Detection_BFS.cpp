#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;


void add_edge(int src, int dest, vector<list<int>> &graph, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

// Function to perform BFS 
bool bfs(int src) {
    vector<int> parent(graph.size(), -1);
    queue<int> q;
    q.push(src);
    visited.insert(src);
    parent[src] = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int neighbor : graph[curr]) {
            // If the neighbor is already visited and not the parent of the current node, then a cycle detected
            if(visited.count(neighbor) and neighbor != parent[curr]) {
                return true;  // Cycle detected
            }
            if (not visited.count(neighbor)) {
                q.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = curr;    // Set the parent of the neighbor to current
            }
        }
    }
    return false;
}

bool hasCycle() {
    visited.clear();
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited.count(i)) {
            if (bfs(i)) {
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
    // add_edge(1, 3, graph);
    add_edge(1, 5, graph);
    add_edge(2, 6, graph);
    add_edge(3, 4, graph);
    add_edge(5, 6, graph);



    cout<<(hasCycle() ? "Cycle detected" : "No cycle detected");


    return 0;
}

/*
    0-----1-----5
    |     |    /
    |     |   /
    4-----3  6-----2
*/