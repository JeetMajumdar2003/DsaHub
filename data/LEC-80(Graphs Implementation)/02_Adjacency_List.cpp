#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<int>> graph;

// Function to add an edge to the graph
void add_edge(int src, int dest, vector<list<int>> &graph, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

// Function to display the graph
void display_graph(const vector<list<int>> &graph) {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Vertex " << i << ":";
        for (const auto &neighbor : graph[i]) {
            cout << "->" << neighbor;
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

    add_edge(0, 1, graph);
    add_edge(0, 2, graph);
    add_edge(1, 5, graph);
    add_edge(2, 3, graph);
    add_edge(2, 5, graph);
    add_edge(3, 6, graph);
    add_edge(6, 4, graph);

    // int e;
    // cin>>e;
    // while (e--) {
    //     int src, dest;
    //     cin >> src >> dest;
    //     add_edge(src, dest, graph);
    // }
    
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