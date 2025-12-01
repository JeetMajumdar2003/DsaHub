/** Triangle - Leetcode-120
 * Given a triangle array, return the minimum path sum from top to bottom.
 * For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row,
 * you may move to either index i or index i + 1 on the next row.
 * 
 * Example 1:
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * [[2],
 *  [3,4],
 *  [6,5,7],
 *  [4,1,8,3]]
 * Output: 11
 * Explanation: The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Example 2:
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * Constraints:
 * 1. 1 <= triangle.length <= 200
 * 2. triangle[0].length == 1
 * 3. triangle[i].length == triangle[i - 1].length + 1
 * 4. -10^4 <= triangle[i][j] <= 10^4
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Top-Down Approach
int minimumTotalTD(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {
    // Base Case
    if(row == triangle.size()) return 0;

    // Memoization
    if(dp[row][col] != -1) return dp[row][col];

    // Recursive Case
    return dp[row][col] = triangle[row][col] + min(minimumTotalTD(triangle, row+1, col, dp), minimumTotalTD(triangle, row+1, col+1, dp));
}

// Bottom-Up Approach
int minimumTotalBU(vector<vector<int>>& triangle) {
    // Method-1: Using 2D DP Array
    // int rows = triangle.size();
    // vector<vector<int>> dp(rows, vector<int>(rows, 0));

    // // Base Case
    // for(int r = 0; r < rows; r++){
    //     dp[rows-1][r] = triangle[rows-1][r];
    // }

    // // Recursive Case
    // for(int r = rows-2; r >= 0; r--){
    //     for(int c = 0; c < triangle[r].size(); c++){
    //         dp[r][c] = triangle[r][c] + min(dp[r+1][c], dp[r+1][c+1]);
    //     }
    // }

    // return dp[0][0];

    // Method-2: Using 1D DP Array
    int rows = triangle.size();
    vector<int> dp = triangle[rows-1];

    // Recursive Case
    for(int r = rows-2; r >= 0; r--){
        for(int c = 0; c < triangle[r].size(); c++){
            dp[c] = triangle[r][c] + min(dp[c], dp[c+1]);
        }
    }

    return dp[0];
}

int minimumTotal(vector<vector<int>>& triangle) {
    // Method-1: Top-Down Approach
    // int rows = triangle.size();
    // vector<vector<int>> dp(rows, vector<int>(rows, -1));
    // return minimumTotalTD(triangle, 0, 0, dp);

    // Method-2: Bottom-Up Approach
    return minimumTotalBU(triangle);
}

int main() {
    vector<vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    cout << "Minimum Path Sum: " << minimumTotal(triangle) << endl;
    return 0;
}