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
    void unionSets(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        // Union by rank
        if (rank[rootA] <= rank[rootB]) {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
        else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
};

int main() {
    DisjointSetUnion dsu(10);
    dsu.unionSets(0, 2);
    dsu.unionSets(2, 3);
    dsu.unionSets(1, 3);
    dsu.unionSets(4, 5);
    dsu.unionSets(6, 7);
    dsu.unionSets(5, 6);

    cout << "1 and 3 are in the same set: " << (dsu.find(1) == dsu.find(3)) << endl;
    cout << "4 and 6 are in the same set: " << (dsu.find(4) == dsu.find(6)) << endl;
    return 0;
}