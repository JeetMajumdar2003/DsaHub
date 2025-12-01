#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    deque<pair<int, int>> dq;
    dq.push_back({0, 0});

    while (!dq.empty())
    {
        auto curr = dq.front();
        int x = curr.first;
        int y = curr.second;
        dq.pop_front();

        int dir = grid[x][y];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];

            int edgeWt = 1;
            if (i + 1 == dir)
                edgeWt = 0;

            if (nx >= 0 and ny >= 0 and nx < n and ny < m)
            {
                // nx, ny lies inside the grid
                if (dist[nx][ny] > dist[x][y] + edgeWt)
                {
                    dist[nx][ny] = dist[x][y] + edgeWt;
                    if (edgeWt == 1)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});
                }
            }
        }
    }

    return dist[n - 1][m - 1];
}

int main() {
    vector<vector<int>> grid = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
    cout << minCost(grid) << endl; // Output: 3
    return 0;
}