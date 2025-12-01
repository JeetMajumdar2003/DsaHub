/** Prim's Algorithm (Minimum Spanning Tree)
 * Data Structures Used:
 * 1. Priority Queue (Min Heap) - to get the edge with the minimum weight
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 * 2. Adjacency List - to represent the graph
        vector<vector<pair<int, int>>> adj(n);
 * 3. Visited Set - to keep track of visited nodes
        unordered_set<int> visited;
 * 4. Unordered Map - to keep track of nodes, discovery weights, and parent nodes
        unordered_map<int, int> nodes;
        unordered_map<int, int> dis;
        unordered_map<int, int> parent;

 * Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices.
 * Space Complexity: O(V + E) for the adjacency list and other data structures.

 * Steps:
    * 1. Initialize the priority queue, visited set, and other data structures.
    * 2. Insert the starting node, typically node->0, into the priority queue with pair(0, 0).
    * 3. While the priority queue is not empty:
        * a. Extract the node with the minimum weight from the priority queue.
        * b. If the node is already visited, continue to the next iteration.
        * c. If the node is not visited, Mark the node as visited and add its weight to the total cost.
        * d. For each neighbour nodes of the current node:
            * i. If the neighbour node is not visited and its weight is less than the current recorded weight:
                * Update the discovery weight and parent node.
                * Insert the neighbour node into the priority queue with its updated weight.
            * ii. If the neighbour node is already visited, skip it.
            * iii. If the neighbour node is not in the priority queue, insert it with its weight.
            * iv. If the neighbour node is in the priority queue but with a higher weight, update its weight and parent node.
    * 4. After processing all nodes, the total cost will represent the weight of the Minimum Spanning Tree (MST).
    * 5. Print the updated MST.
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

// Prims Algorithm to find the weight of the Minimum Spanning Tree (MST)
int primsMST(int src, vector<list<pp>>& graph)
{
    // Priority Queue (Min Heap) to get the edge with the minimum weight
    priority_queue<pp, vector<pp>, greater<pp>> pq;

    // Visited Set to keep track of visited nodes
    unordered_set<int> visited;

    // Unordered Maps to keep track of nodes, discovery weights, and parent nodes
    unordered_map<int, int> nodes;  // node -> weight
    unordered_map<int, int> dis;    // node -> discovery weight
    unordered_map<int, int> parent; // node -> parent node

    // Initialize the priority queue with the starting node (node 0 with weight 0)
    pq.push({0, src});
    nodes[src] = 0;
    dis[src] = 0;
    parent[src] = -1;

    int totalCost = 0; // To store the total cost of the MST

    while (!pq.empty())
    {
        // Extract the node with the minimum weight from the priority queue
        auto [weight, node] = pq.top();
        pq.pop();

        // If the node is already visited, skip it
        if (visited.find(node) != visited.end())
            continue;

        // Mark the node as visited and add its weight to the total cost
        visited.insert(node);
        totalCost += weight;

        // Explore all neighbour nodes of the current node
        for (auto &[neighbour, edgeWeight] : graph[node])
        {
            // If the neighbour node is not visited and its weight is less than the current recorded weight
            if (visited.find(neighbour) == visited.end())
            {
                if (dis.find(neighbour) == dis.end() || edgeWeight < dis[neighbour])
                {
                    // Update the discovery weight and parent node
                    dis[neighbour] = edgeWeight;
                    parent[neighbour] = node;

                    // Insert the neighbour node into the priority queue with its updated weight
                    pq.push({edgeWeight, neighbour});
                    nodes[neighbour] = edgeWeight;
                }
            }
        }
    }
    
    // Print the edges of the Minimum Spanning Tree (MST)
    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    for (const auto& [node, par] : parent) {
        if (par != -1) { // Skip the source node which has no parent
            cout << par << " - " << node << " with weight " << dis[node] << "\n";
        }
    }

    return totalCost; // Return the total cost of the Minimum Spanning Tree (MST)
}

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m; // Number of vertices and edges

    graph.resize(n+1, list<pp>());  // Resizing the graph to n+1 for 1 based indexing

    // Read edges
    cout << "Enter edges (u v wt):\n";
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        addEdge(u, v, wt);     // For 0 based indexing(Edges start from 0 to n-1)
        // addEdge(u - 1, v - 1, wt); // For 1 based indexing(Edges start from 1 to n), No Need as we have resized the graph to n+1
    }

    int src;
    cout << "Enter the Source Node: ";
    cin >> src;


    // int n = 9; // Number of nodes
    // int m = 12; // Number of edges
    // int src = 0; 
    // graph.resize(src, list<pp>());

    // // Example graph represented as an adjacency list, where each pair is (neighbour, weight)
    // addEdge(0, 1, 4);
    // addEdge(0, 4, 1);
    // addEdge(0, 7, 3);
    // addEdge(1, 2, 1);
    // addEdge(2, 3, 4);
    // addEdge(2, 4, 1);
    // addEdge(3, 6, 2);
    // addEdge(4, 5, 4);
    // addEdge(4, 8, 2);
    // addEdge(5, 6, 3);
    // addEdge(5, 8, 3);
    // addEdge(7, 8, 1);

    int totalCost = primsMST(src, graph);
    cout << "Total cost of Minimum Spanning Tree (MST): " << totalCost << endl;

    return 0;
}

/**
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
 * Output: 14

 * Smaple Input: (1 Based)
5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
1
 * Expected Output: 15

 * Sample Input: (1 Based)
5 7
1 2 20
1 3 50
1 4 70
1 5 90
2 3 30
3 4 40
4 5 60
2
 * Expected Output: 150
 */