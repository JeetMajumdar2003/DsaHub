#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<unordered_map<int, int>> graph;

// Function to add an edge to the graph
void add_edge(int src, int dest, int weight, vector<unordered_map<int, int>> &graph, bool bi_dir = true) {
    graph[src][dest] = weight;
    if (bi_dir) {
        graph[dest][src] = weight;
    }
}

// Function to display the graph
void display_graph(const vector<unordered_map<int, int>> &graph) {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Vertex " << i << ":";
        for (const auto &neighbor : graph[i]) {
            cout << "->(" << neighbor.first << ", " << neighbor.second << ")";
        }
        cout << endl;
    }

    return;
}

int main() {
    int v;  // Number of vertices
    v = 7;  // Example: 7 vertices
    // cin>>v;
    graph.resize(v);

    add_edge(0, 1, 1, graph);
    add_edge(0, 2, 2, graph);
    add_edge(1, 5, 3, graph);
    add_edge(2, 3, 6, graph);
    add_edge(2, 5, 2, graph);
    add_edge(3, 6, 2, graph);
    add_edge(6, 4, 9, graph);
    
    // Print the adjacency list
    display_graph(graph);

    return 0;
}

/*
//   0-----2-----3
//   |     |    /
//   |     |   /
//   1-----5  6-----4
*/