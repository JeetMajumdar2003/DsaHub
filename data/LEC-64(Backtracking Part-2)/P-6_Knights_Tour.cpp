#include <iostream>
#include <vector>
using namespace std;

bool knightsTour(vector<vector<int>>& grid, int i, int j, int n, int count){
    // Base Case(returing condition)
    if (i<0 or j<0 or i>=n or j>=n or grid[i][j]>=0) return false;

    // count the number of moves: current position
    grid[i][j] = count;

    // print the chess board after completing the tour
    if (count == n*n-1){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cout << grid[i][j] << "\t";
            }
            cout << endl;
        }
        return true;
    }

    // Recursive Cases:
    if(knightsTour(grid, i-2, j-1, n, count+1)) return true;
    if(knightsTour(grid, i-2, j+1, n, count+1)) return true;
    if(knightsTour(grid, i-1, j-2, n, count+1)) return true;
    if(knightsTour(grid, i-1, j+2, n, count+1)) return true;
    if(knightsTour(grid, i+2, j-1, n, count+1)) return true;
    if(knightsTour(grid, i+2, j+1, n, count+1)) return true;
    if(knightsTour(grid, i+1, j-2, n, count+1)) return true;
    if(knightsTour(grid, i+1, j+2, n, count+1)) return true;

    // Backtracking
    grid[i][j] = -1;

    return false;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    knightsTour(grid, 0, 0, n, 0);
    return 0;
}

/** Generated bu Copilot:
    * Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules of chess knight must visit each square exactly once. Print the order of each the cell in which they are visited.
    * 
    * Input:
    * The first line of input contains an integer T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.
    * 
    * Output:
    * For each testcase, in a new line, print the order of cells in which they are visited.
    * 
    * Constraints:
    * 1 <= T <= 100
    * 1 <= N <= 20
    * 
    * Example:
    * Input:
    * 1
    * 5
    * Output:
        0       11      2       17      20
        3       16      19      12      7
        10      1       6       21      18
        15      4       23      8       13
        24      9       14      5       22
    * Explanation:
    * Testcase 1: Knight placed on the first block and makes a tour to all the blocks.
    
bool isSafe(int x, int y, vector<vector<int>> &board) {
    if(x >= 0 && x < board.size() && y >= 0 && y < board.size() && board[x][y] == -1) {
        return true;
    }
    return false;
}

bool solveKT(int x, int y, int move, vector<vector<int>> &board, vector<int> &xMove, vector<int> &yMove) {
    if(move == board.size() * board.size()) {
        return true;
    }
    for(int i = 0; i < 8; i++) {
        int nextX = x + xMove[i];
        int nextY = y + yMove[i];
        if(isSafe(nextX, nextY, board)) {
            board[nextX][nextY] = move;
            if(solveKT(nextX, nextY, move + 1, board, xMove, yMove)) {
                return true;
            } else {
                board[nextX][nextY] = -1;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, -1));
    vector<int> xMove = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> yMove = {1, 2, 2, 1, -1, -2, -2, -1};
    board[0][0] = 0;
    if(solveKT(0, 0, 1, board, xMove, yMove)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist" << endl;
    }
    return 0;
}
*/