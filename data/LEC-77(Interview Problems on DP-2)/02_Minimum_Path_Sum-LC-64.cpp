/** Minimum Path Sum: https://leetcode.com/problems/minimum-path-sum/
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all
 * numbers along its path.
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * Input: grid = [[1,3,1],
 *                [1,5,1],
 *                [4,2,1]]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * Constraints:
 * 1 <= grid.length <= 200
 * 1 <= grid[0].length <= 200
 * 0 <= grid[i][j] <= 100
 * 
 * Approach:
 * 1. Initialize a 2D array dp of the same size as the grid, where dp[i][j] represents the minimum path sum to reach cell (i, j).
 * 2. Set dp[0][0] to grid[0][0], as the starting cell is the first cell in the grid.
 * 3. Fill the first row and first column of dp.
 * 4. Iterate through each cell in the grid.
 * 5. Calculate the minimum path sum to reach the current cell by taking the minimum of the cell above (dp[i-1][j]) and the cell to the left (dp[i][j-1]), and adding the value of the current cell (grid[i][j]).
 * 6. Return the value in the bottom-right cell (dp[m-1][n-1]), which represents the minimum path sum.
 * * Complexity Analysis:
 * Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
 * Space Complexity: O(m * n), as we are using a 2D array to store the minimum path sums.
 * 
 * Note: The space complexity can be optimized to O(n) by using a 1D array instead of a 2D array.
 */

#include <iostream>
#include <vector>
using namespace std;

// Top-Down Approach
int minPathSum(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    int m = grid.size();
    int n = grid[0].size();

    // Base case: If the current cell is out of bounds, return a large value
    if (i >= m || j >= n) {
        return INT_MAX;
    }
    // Base case: If we reach the bottom-right corner, return the value of that cell
    if (i == m - 1 && j == n - 1) {
        return grid[i][j];
    }
    // Check if the result is already computed
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // Recursive calls to move down and right
    int down = minPathSum(grid, i + 1, j, dp);
    int right = minPathSum(grid, i, j + 1, dp);

    // Store the minimum path sum in dp[i][j]
    dp[i][j] = min(down, right) + grid[i][j];
    return dp[i][j];
}

// Bottom-Up Approach
int minPathSumBU(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the starting cell
    dp[m - 1][n - 1] = grid[m - 1][n - 1];

    // Fill the last row
    for (int j = n - 2; j >= 0; j--) {
        dp[m - 1][j] = dp[m - 1][j + 1] + grid[m - 1][j];
    }

    // Fill the last column
    for (int i = m - 2; i >= 0; i--) {
        dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
    }

    // Fill the rest of the dp table
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
        }
    }

    return dp[0][0];
}

// Optimized Space Complexity
int minPathSumOpt(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(n, 0);

    // Initialize the starting cell
    dp[n - 1] = grid[m - 1][n - 1];

    // Fill the last row
    for (int j = n - 2; j >= 0; j--) {
        dp[j] = dp[j + 1] + grid[m - 1][j];
    }

    // Fill the rest of the dp array
    for (int i = m - 2; i >= 0; i--) {
        dp[n - 1] += grid[i][n - 1];
        for (int j = n - 2; j >= 0; j--) {
            dp[j] = min(dp[j], dp[j + 1]) + grid[i][j];
        }
    }

    return dp[0];
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1},
                                 {1, 5, 1},
                                 {4, 2, 1}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << "Minimum Path Sum (Top-Down): " << minPathSum(grid, 0, 0, dp) << endl;
    cout << "Minimum Path Sum (Bottom-Up): " << minPathSumBU(grid) << endl;
    cout << "Minimum Path Sum (Optimized): " << minPathSumOpt(grid) << endl;

    return 0;
}