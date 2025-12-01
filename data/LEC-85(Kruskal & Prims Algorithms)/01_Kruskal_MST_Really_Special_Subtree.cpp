/** Kruskal's Algorithm (Minimum Spanning Tree)
 * To create the Really Special SubTree, always pick the edge with smallest weight. Determine if including it will create a cycle. If so, ignore the edge. If there are edges of equal weight available:
 * Choose the edge that minimizes the sum (u + v + wt) where u and v are vertices and wt is the edge weight.
 * If there is still a collision, choose any of them.
 * 
 * Steps:
 * 1. Sort all the edges in non-decreasing order of their weight. If two edges have the same weight, sort them by the sum (u + v + wt).
 * 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
 * 3. Use DSU (Disjoint Set Union) to detect cycle.
 */

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Class to represent Disjoint Set Union (Union-Find) data structure
class DisjointSetUnion {
private:
    vector<int> parent, rank;

public:
    DisjointSetUnion(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        // Initialize the parent array
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Returns the representative (root) of the group/cluster containing x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    // Unites the sets containing elements a and b
    bool detectCycle(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        // If they are already in the same set, a cycle is detected
        if(rootA == rootB) {
            return true;
        }

        // Union by rank
        if (rank[rootA] <= rank[rootB]) {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
        else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return false;
    }
};

// Class to represent an edge list and handle sorting
class EdgeList {
private:
    struct Edge {
        int u, v, wt;
    };
    
public:
    vector<Edge> edges;

    // Add an edge to the edge list
    void addEdge(int u, int v, int wt) {
        edges.push_back({u, v, wt});
    }

    // Custom comparator to sort edges by weight, then by (u + v + wt)
    static bool compareEdges(const Edge& a, const Edge& b) {
        if (a.wt != b.wt) {
            return a.wt < b.wt; // Sort by weight
        }
        return (a.u + a.v + a.wt) < (b.u + b.v + b.wt); // Sort by (u + v + wt)
    }

    // Sort edges using the custom comparator
    void sortEdges() {
        sort(edges.begin(), edges.end(), compareEdges);
    }
};

// Kruskal's algorithm to find the weight of the Minimum Spanning Tree (MST)
ll kruskalMST(int n, EdgeList& edgeList) {
    DisjointSetUnion dsu(n);
    ll totalWeight = 0;

    // Sort edges based on the custom criteria
    edgeList.sortEdges();

    // Iterate through sorted edges and apply Kruskal's algorithm
    for (const auto& edge : edgeList.edges) {
        if (!dsu.detectCycle(edge.u, edge.v)) { // If no cycle is formed
            totalWeight += edge.wt; // Include this edge in MST
        }
    }

    return totalWeight;
}

// M-2(No Need As We Have Handled Both 0 Based and 1 Based Input in Main Function, by incrementing DSU Size from n to n+1)
int KruskalHelper() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges

    EdgeList edgeList;

    // Read edges
    // Read raw edges first so we can detect whether input is 0-based or 1-based.
    vector<tuple<int,int,int>> rawEdges;
    rawEdges.reserve(m);
    int maxVertex = -1;
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        rawEdges.emplace_back(u, v, wt);
        maxVertex = max(maxVertex, max(u, v));
    }

    // If maxVertex == n then input is likely 1-based (vertices in [1..n]).
    // If maxVertex == n-1 then input is 0-based (vertices in [0..n-1]).
    bool inputIsOneBased = (maxVertex == n);
    bool inputIsZeroBased = (maxVertex <= n - 1);
    if (!inputIsOneBased && !inputIsZeroBased) {
        // Unexpected vertex numbering; still attempt to treat as 0-based but warn via cerr.
        cerr << "Warning: detected max vertex " << maxVertex << " for n=" << n << ".\n";
    }

    for (auto &t : rawEdges) {
        int u, v, wt;
        tie(u, v, wt) = t;
        if (inputIsOneBased) {
            edgeList.addEdge(u - 1, v - 1, wt);
        } else {
            edgeList.addEdge(u, v, wt);
        }
    }

    ll result = kruskalMST(n, edgeList);
    cout << result << "\n"; // Output the total weight of the MST

    return 0;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges:\n";
    cin >> n >> m; // Number of vertices and edges

    EdgeList edgeList;

    // Read edges
    cout << "Enter edges (u v wt):\n";
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edgeList.addEdge(u, v, wt);     // For 0 based indexing(Edges start from 0 to n-1)
        // cin >> u >> v >> wt; edgeList.addEdge(u - 1, v - 1, wt); // For 1 based indexing(Edges start from 1 to n), No Need as we have incremented DSU size from n to n+1
    }

    ll result = kruskalMST(n+1, edgeList);  // n+1 for 1 based indexing
    cout << "Total weight of the MST: " << result << "\n"; // Output the total weight of the MST

    // KruskalHelper();

    return 0;
}


/**
 * Sample Input: (0 based)
7 8
0 1 2
1 2 4     
2 3 1
3 0 2
1 4 2
4 5 5
5 6 3
6 4 1
 * Sample Output: 11

 * Sample Input: (1 based)
5 7
1 2 20
1 3 50
1 4 70
1 5 90
2 3 30
3 4 40
4 5 60
 * Sample Output: 150
 */