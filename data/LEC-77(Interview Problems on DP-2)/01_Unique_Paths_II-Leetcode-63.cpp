/** Unique Paths II
 * This problem is about finding the number of unique paths available in a grid
 * that may contain obstacles.
 * The grid is represented as a 2D array, where 0 represents an empty cell and 1 represents an obstacle.
 * The robot can only move down or right.
 * The goal is to find the number of unique paths from the top-left corner to the bottom-right corner.
 * 
 * Approach
 * 1. Initialize a 2D array dp of the same size as the grid, where dp[i][j] represents the number of unique paths to reach cell (i, j).
 * 2. If the starting cell (0, 0) or the ending cell (m-1, n-1) is an obstacle, return 0.
 * 3. Set dp[0][0] to 1, as there is one way to reach the starting cell.
 * 4. Iterate through each cell in the grid.
 * 5. If the current cell is an obstacle, set dp[i][j] to 0.
 * 6. Otherwise, calculate the number of unique paths to reach the current cell by summing the values from the cell above (dp[i-1][j]) and the cell to the left (dp[i][j-1]).
 * 7. Return the value in the bottom-right cell (dp[m-1][n-1]), which represents the total number of unique paths.
 * 
 * Complexity Analysis
 * Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
 * Space Complexity: O(m * n), as we are using a 2D array to store the number of unique paths.
 * 
 * Note: The space complexity can be optimized to O(n) by using a 1D array instead of a 2D array.
 * 
 * Example
 * Input: grid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There are two unique paths to reach the bottom-right corner.
 * 
 * Constraints
 * 1 <= m, n <= 100
 * 0 <= grid[i][j] <= 1
 * The starting cell and the ending cell are guaranteed to be empty.
 */

#include <iostream>
#include <vector>
using namespace std;

// Top-Down Approach
int uniquePathsWithObstacles(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    int m = grid.size();
    int n = grid[0].size();

    // Base case: If the current cell is out of bounds or an obstacle, return 0
    if (i >= m || j >= n || grid[i][j] == 1) {
        return 0;
    }
    // Base case: If we reach the bottom-right corner, return 1
    if (i == m - 1 && j == n - 1) {
        return 1;
    }
    // Check if the result is already computed
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // Recursive calls to move down and right
    int down = uniquePathsWithObstacles(grid, i + 1, j, dp);
    int right = uniquePathsWithObstacles(grid, i, j + 1, dp);

    // Store the total unique paths in dp[i][j]
    dp[i][j] = down + right;
    return dp[i][j];
}

// Bottom-Up Approach
int uniquePathsWithObstaclesBU(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Base case: If the starting cell is an obstacle, return 0
    if (grid[0][0] == 1) {
        return 0;
    }
    // Base case: If the ending cell is an obstacle, return 0
    if (grid[m - 1][n - 1] == 1) {
        return 0;
    }

    // // Method - 1: (0, 0) -> (m-1, n-1)
    // // Initialize the starting cell
    // dp[0][0] = 1;

    // // Fill the first row
    // for (int j = 1; j < n; j++) {
    //     dp[0][j] = (grid[0][j] == 0) ? dp[0][j - 1] : 0;
    // }

    // // Fill the first column
    // for (int i = 1; i < m; i++) {
    //     dp[i][0] = (grid[i][0] == 0) ? dp[i - 1][0] : 0;
    // }

    // // Fill the rest of the dp table
    // for (int i = 1; i < m; i++) {
    //     for (int j = 1; j < n; j++) {
    //         if (grid[i][j] == 0) {
    //             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //         }
    //     }
    // }

    // return dp[m - 1][n - 1];

    // Method - 2: (m-1, n-1) -> (0, 0)
    // Initialize the ending cell
    dp[m - 1][n - 1] = 1;
    // Fill the last row
    for (int j = n - 2; j >= 0; j--) {
        dp[m - 1][j] = (grid[m - 1][j] == 0) ? dp[m - 1][j + 1] : 0;
    }
    // Fill the last column
    for (int i = m - 2; i >= 0; i--) {
        dp[i][n - 1] = (grid[i][n - 1] == 0) ? dp[i + 1][n - 1] : 0;
    }
    // Fill the rest of the dp table
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (grid[i][j] == 0) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Top-Down Approach
    int resultTD = uniquePathsWithObstacles(grid, 0, 0, dp);
    cout << "Top-Down Approach: " << resultTD << endl;

    // Bottom-Up Approach
    int resultBU = uniquePathsWithObstaclesBU(grid);
    cout << "Bottom-Up Approach: " << resultBU << endl;

    return 0;
}