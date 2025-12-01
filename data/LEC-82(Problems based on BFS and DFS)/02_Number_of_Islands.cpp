#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int rows, cols;
vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int i, int j, vector<vector<char>>& grid){
    if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]=='0') return;

    grid[i][j]='0';
    dfs(i+1, j, grid);
    dfs(i, j+1, grid);
    dfs(i-1, j, grid);
    dfs(i, j-1, grid);
}
int numIslandsDFS(vector<vector<char>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    int count = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j] != '0'){
                dfs(i, j, grid);
                count++;
            }
        }
    }

    return count;
}

int numIslandsBFS(vector<vector<char>>& grid) {
    rows = grid.size();
    cols = grid[0].size();

    int count = 0;
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            if (grid[r][c] == '0'){
                continue;
            }
            count++;
            grid[r][c] = '0';
            queue<pair<int, int>> q;
            q.push({r, c});
            while(!q.empty()){
                auto [currRow, currCol] = q.front();
                q.pop();

                for(auto [dx, dy] : directions){
                    int nx = currRow + dx, ny = currCol + dy;
                    if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1'){
                        grid[nx][ny] = '0';
                        q.push({nx, ny});
                    }
                }
                // OR
                // if(currRow - 1 >= 0 && grid[currRow - 1][currCol] == '1'){
                //     grid[currRow - 1][currCol] = '0';
                //     q.push({currRow - 1, currCol});
                // }
                // if(currRow + 1 < rows && grid[currRow + 1][currCol] == '1'){
                //     grid[currRow + 1][currCol] = '0';
                //     q.push({currRow + 1, currCol});
                // }
                // if(currCol - 1 >= 0 && grid[currRow][currCol - 1] == '1'){
                //     grid[currRow][currCol - 1] = '0';
                //     q.push({currRow, currCol - 1});
                // }
                // if(currCol + 1 < cols && grid[currRow][currCol + 1] == '1'){
                //     grid[currRow][currCol + 1] = '0';
                //     q.push({currRow, currCol + 1});
                // }
            }
        }
    }

    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int result;
    // result = numIslandsDFS(grid);
    // cout << "Number of islands (DFS): " << result << endl;

    result = numIslandsBFS(grid);
    cout << "Number of islands (BFS): " << result << endl;

    return 0;
}