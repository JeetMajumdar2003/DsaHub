/** Maximal Rectangle - LeetCode 85
 * Problem Statement:
 * Given a binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 * 
 * This problem involves finding the largest rectangle containing only 1's in a binary matrix.
 * We can utilize dynamic programming to solve this efficiently.
 *
 * The approach involves calculating the height of contiguous 1's for each column and using a 
 * stack to determine the maximal rectangle area for each row considering these heights.
 * 
 * Example 1:
 * Input: matrix = [["1","0","0","0","0"],
 *                  ["1","0","1","1","1"],
 *                  ["1","1","1","1","1"],
 *                  ["0","1","0","0","0"]]
 * Output: 6
 * Explanation: The maximal rectangle is formed by 1's in the last three rows
 * where the area is 3 x 2 = 6.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int maxArea = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Update the height of the current column
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }

        // Calculate the maximal rectangle area for the current row
        stack<int> s;
        for (int j = 0; j <= cols; ++j) {
            int h = (j == cols) ? 0 : heights[j];
            while (!s.empty() && heights[s.top()] > h) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? j : j - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(j);
        }
    }

    return maxArea;
}

int main() {
    // Example usage
    vector<vector<char>> matrix = {
        {'1', '0', '0', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'0', '1', '0', '0', '0'}
    };

    int result = maximalRectangle(matrix);
    cout << "The area of the largest rectangle containing only 1's is: " << result << endl; // Output: 6

    return 0;
}