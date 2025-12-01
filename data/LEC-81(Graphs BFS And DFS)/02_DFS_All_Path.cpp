#include <iostream>
#include <vector>
#include <list>
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

void dfs(int curr, int end, vector<int> &path){
    // If the curr node is the destination, return true
    if (curr == end) {
        path.push_back(curr);
        result.push_back(path); // Store the current path
        path.pop_back(); // Backtrack
        return;
    }

    visited.insert(curr);    // Mark the current node as visited
    path.push_back(curr);    // Add current node to the path
    
    // Explore all neighbors
    for (int neighbor : graph[curr]) {
        // If the neighbor has not been visited, continue DFS
        if (!visited.count(neighbor)) {     // or visited.find(neighbor) == visited.end()
            dfs(neighbor, end, path);
        }
    }

    path.pop_back();     // Backtrack: remove current node from path
    visited.erase(curr); // Backtrack: unmark the current node
    
    return;
}

vector<vector<int>> allPath(int src, int dest){
    visited.clear();  // Clear visited set for new DFS
    result.clear();   // Clear previous results
    vector<int> path;
    dfs(src, dest, path);
    return result;
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


    vector<vector<int>> paths = allPath(0, 6);
    cout << "All paths from 0 to 6:" << endl;
    for (const auto& path : paths) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    0-----1-----5
    |     |    / \
    |     |   /   \
    4-----3  6-----2
*/