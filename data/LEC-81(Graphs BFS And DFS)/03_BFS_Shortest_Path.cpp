#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
vector<vector<int>> result;
unordered_set<int> visited;


void add_edge(int src, int dest, vector<list<int>> &graph, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

// Function to perform BFS and find the shortest path from src to dest
void bfs(int src, vector<int> &dist) {
    queue<int> q;
    q.push(src);
    visited.insert(src);
    dist[src] = 0;

    cout << "BFS traversal starting from node " << src << ": ";
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int neighbor : graph[curr]) {
            if (not visited.count(neighbor)) {
                q.push(neighbor);
                visited.insert(neighbor);
                dist[neighbor] = dist[curr] + 1;
            }
        }
    }
    cout << endl;
}

int main() {
    int v = 7;
    graph.resize(v);
    visited.clear();

    add_edge(0, 1, graph);
    add_edge(0, 4, graph);
    add_edge(1, 3, graph);
    add_edge(1, 5, graph);
    add_edge(2, 5, graph);
    add_edge(2, 6, graph);
    add_edge(3, 4, graph);
    add_edge(5, 6, graph);

    vector<int> dist(v, -1);
    bfs(0, dist);

    cout << "Shortest path from 0 to 6 is: " << dist[6] << endl;

    return 0;
}

/*
    0-----1-----5
    |     |    / \
    |     |   /   \
    4-----3  6-----2
*/