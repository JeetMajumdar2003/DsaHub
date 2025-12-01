/** Dijkstra's Algorithm: Single Source Shortest Path (SSSP) in a Weighted Graph
 *   - This implementation uses a priority queue (min-heap) to efficiently get the next node with the smallest distance.
 *   - The graph is represented as an adjacency list using a vector of lists.
 *   - The algorithm handles graphs with non-negative weights.
 *   - The time complexity is O((V + E) log V), where V is the number of vertices and E is the number of edges.
 * 
 * Steps to implement Dijkstra's Algorithm:
 *     1. Initialize the priority queue, distance map, and visited set.
 *     2. Insert the starting node into the priority queue with a distance of 0.
 *     3. While the priority queue is not empty:
 *        a. Extract the node with the minimum distance.
 *        b. If the node is already visited, continue to the next iteration.
 *        c. Mark the node as visited.
 *        d. For each neighbor of the current node:
 *           i. If the neighbor is not visited and the edge weight is less than the recorded distance:
 *              Update the distance and insert the neighbor into the priority queue.
 *     4. After processing all nodes, the distance map will contain the shortest paths from the source.
 */

#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int, int>
using namespace std;

vector<list<pp>> graph;

void addEdge(int u, int v, int wt, bool biDir=true){
    graph[u].push_back({v, wt});
    if(biDir){
        graph[v].push_back({u, wt});
    }
}

void printCompleteShortestPathBetween2Nodes(int src, int dest, unordered_map<int, int> &dist, unordered_map<int, int>& via) {
    if (dist.find(dest) == dist.end()) {
        cout << "No path exists from node " << src << " to node " << dest << ".\n";
        return;
    }

    vector<int> path;
    for (int at = dest; at != -1; at = via[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    cout << "Shortest path from node " << src << " to node " << dest << " is: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << " with total distance " << dist[dest] << "\n";
}

// Dijkstra's Algorithm to find the shortest path from source to all other nodes
void dijkstra(int src, vector<list<pp>>& graph)
{
    // Priority Queue (Min Heap) to get the node with the minimum distance
    priority_queue<pp, vector<pp>, greater<pp>> pq;

    // Visited Set to keep track of visited nodes
    unordered_set<int> visited;

    // Unordered Maps to keep track of nodes, distances, and via nodes
    unordered_map<int, int> nodes;  // node -> distance
    unordered_map<int, int> dist;    // node -> shortest distance from source
    unordered_map<int, int> via; // node -> via node in the shortest path

    // Initialize the priority queue with the starting node (source with distance 0)
    pq.push({0, src});
    nodes[src] = 0;
    dist[src] = 0;
    via[src] = -1; // Source has no via

    while (!pq.empty())
    {
        // Extract the node with the minimum distance from the priority queue
        auto [currentDist, node] = pq.top();
        pq.pop();

        // If the node is already visited, skip it
        if (visited.find(node) != visited.end()) {
            continue;
        }

        // Mark the node as visited
        visited.insert(node);

        // Explore all neighbors of the current node
        for (const auto& [neighbour, edgeWeight] : graph[node])
        {
            // If the neighbour node is not visited and its weight is less than the current recorded weight
            if (visited.find(neighbour) == visited.end())
            {
                if (dist.find(neighbour) == dist.end() || currentDist + edgeWeight < dist[neighbour])
                {
                    // Update the shortest distance and via node (Relaxation Algorithm)
                    dist[neighbour] = currentDist + edgeWeight;
                    via[neighbour] = node;

                    // Insert the neighbour node into the priority queue with its updated distance
                    pq.push({dist[neighbour], neighbour});
                    nodes[neighbour] = dist[neighbour];
                }
            }
        }
    }
    
    // // Print the shortest paths from source to all other nodes
    // cout << "\nShortest paths from source node " << src << ":\n";
    // for (const auto& [node, distance] : dist) {
    //     cout << "Node " << node << " has shortest distance " << distance << "\n";
    // }
    // cout << "\n";

    // Print the shortest paths from source to all other nodes
    cout << "Shortest paths from source node " << src << ":\n";
    for (const auto& [node, distance] : dist) {
        cout << "Node " << node << " has shortest distance " << distance;
        if (via.at(node) != -1) {
            cout << " via node " << via.at(node);
        }
        cout << "\n";
    }

    printCompleteShortestPathBetween2Nodes(src, 5, dist, via);
    
    return;
}

int main()
{
    int n, m; // Number of nodes and edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    graph.resize(n+1, list<pp>());  // Resizing the graph to n+1 for 1 based indexing

    cout << "Enter the edges (u v weight) - 0/1 based indexing:\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        addEdge(u, v, wt);
    }

    int src;
    cout << "Enter the Source Node: ";
    cin >> src;

    // For 0 based indexing(Edges start from 0 to n-1)
    // For 1 based indexing(Edges start from 1 to n), No Need as we have resized the graph to n+1

    dijkstra(src, graph);

    return 0;
}

/*
Dijkstra's Algorithm Implementation
 * Sample Input: (0 Based)
7 9
0 1 2
0 2 5
1 2 6
1 2 2
2 4 1
3 4 2
3 6 1
4 5 6
6 5 1
0
 * Sample Output:
Shortest paths from source node 0:
Node 0 has shortest distance 0
Node 1 has shortest distance 2
Node 2 has shortest distance 4
Node 4 has shortest distance 5
Node 3 has shortest distance 7
Node 6 has shortest distance 8
Node 5 has shortest distance 9

 * Sample Input: (0 Based)
9 12
0 1 4
0 4 1
0 7 3
1 2 1
2 3 4
2 4 1
3 6 2
4 5 4
4 8 2
5 6 3
5 8 3
7 8 1
0
 * Sample Output:
Shortest paths from source node 0:
Node 0 has shortest distance 0
Node 1 has shortest distance 3
Node 4 has shortest distance 1
Node 7 has shortest distance 3
Node 2 has shortest distance 2
Node 3 has shortest distance 6
Node 6 has shortest distance 8
Node 5 has shortest distance 5
Node 8 has shortest distance 3

 * Smaple Input: (1 Based)
5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
1
 * Sample Output:
Shortest paths from source node 1:
Node 1 has shortest distance 0
Node 2 has shortest distance 3
Node 3 has shortest distance 4
Node 4 has shortest distance 9
Node 5 has shortest distance 5
*/