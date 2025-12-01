#include <iostream>
#include <vector>
using namespace std;

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
    bool unionSets(int a, int b) {
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

int main() {
    // Edgelist
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {3, 6}, {6, 7}, {7, 8}, {7, 9}
    };

    DisjointSetUnion dsu(10);

    for (const auto& edge : edges) {
        if (dsu.unionSets(edge.first, edge.second)) {
            cout << "Cycle detected between: " << edge.first << " and " << edge.second << endl;
        }
    }

    return 0;
}