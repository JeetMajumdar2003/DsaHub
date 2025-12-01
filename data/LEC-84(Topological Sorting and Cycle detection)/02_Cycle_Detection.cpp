#include <iostream>
#include <vector>
using namespace std;

// Detect cycle in a grid where each cell points to exactly one neighbor
// using DFS with 3-color marking (0 = unvisited, 1 = visiting, 2 = done).
// Time complexity: O(n*m)
// Space complexity: O(n*m) (call stack + state array)

int n, m;

pair<int,int> nextCell(int i, int j, const vector<vector<char>>& matrix) {
    char c = matrix[i][j];
    if (c == 'L') return {i, j - 1};
    if (c == 'R') return {i, j + 1};
    if (c == 'U') return {i - 1, j};
    if (c == 'D') return {i + 1, j};
    return {-1, -1}; // unknown char - treat as out of bounds/no-next
}

bool dfs(int i, int j, const vector<vector<char>>& matrix, vector<vector<int>>& state) {
    // state: 0 = unvisited, 1 = visiting, 2 = done
    if (i < 0 || i >= n || j < 0 || j >= m) return false; // went out of bounds -> no cycle here
    if (state[i][j] == 1) return true;  // reached a node in current recursion stack => cycle
    if (state[i][j] == 2) return false; // already processed and no cycle from here

    state[i][j] = 1; // mark visiting
    auto [ni, nj] = nextCell(i, j, matrix);

    bool foundCycle = false;
    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
        foundCycle = dfs(ni, nj, matrix, state);
    } else {
        // next goes out of bounds -> path ends, no cycle through this edge
        foundCycle = false;
    }

    state[i][j] = 2; // mark done
    return foundCycle;
}

bool hasCycleUtil(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return false;
    n = matrix.size();
    m = matrix[0].size();

    vector<vector<int>> state(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (state[i][j] == 0) {
                if (dfs(i, j, matrix, state)) return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> matrix = {
        {'R', 'R', 'D', 'R'},
        {'D', 'L', 'D', 'L'},
        {'D', 'U', 'L', 'D'},
        {'R', 'R', 'R', 'R'}
    };

    cout << hasCycleUtil(matrix);
    return 0;
}