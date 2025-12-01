/** Matrix Chain Multiplication - GFG (https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#)
 * Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum. When two matrices of size m*n and n*p when multiplied, they generate a matrix of size m*p and the number of multiplications performed is m*n*p.
 * The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
 *
 * Example 1:
 * Input: N = 5, arr[] = {40, 20, 30, 10, 30}
 * Output: 26000
 * Explanation: There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30. 
 *              Say the matrices are named A, B, C, D. The efficient way is (A*(B*C))*D. 
 *              The number of operations are 20*30*10 + 40*20*10 + 40*10*30 = 26000.
 *
 * Example 2:
 * Input: N = 4, arr[] = {10, 30, 5, 60}
 * Output: 4500
 * Explanation: The matrices have dimensions 10*30, 30*5, 5*60. 
 *              Say the matrices are A, B and C. The most efficient way is (A*B)*C. 
 *              The number of multiplications are 10*30*5 + 10*5*60 = 4500.
 *
 * Example 3:
 * Input: arr[] = {2, 1, 3, 4}
 * Output: 20
 * Explanation: There are 3 matrices of dimensions 2×1, 1×3, and 3×4.
 *              Let the input 3 matrices be M1, M2, and M3. There are two ways to multiply ((M1 x M2) x M3) and (M1 x (M2 x M3)).
 *              Please note that the result of M1 x M2 is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix.
 *              ((M1 x M2) x M3) requires (2 x 1 x 3) + (0) + (2 x 3 x 4) = 30
 *              (M1 x (M2 x M3)) requires (0) + (1 x 3 x 4) + (2 x 1 x 4) = 20
 *              The minimum of these two is 20.
 *
 * Example 4:
 * Input: arr[] = {1, 2, 3, 4, 3}
 * Output: 30
 * Explanation: There are 4 matrices of dimensions 1×2, 2×3, 3×4, 4×3. 
 *              Let the input 4 matrices be M1, M2, M3 and M4. 
 *              The minimum number of multiplications are obtained by ((M1M2)M3)M4. 
 *              The minimum number is 1*2*3 + 1*3*4 + 1*4*3 = 30.
 *
 * Example 5:
 * Input: arr[] = {3, 4}
 * Output: 0
 * Explanation: As there is only one matrix so, there is no cost of multiplication.
 *
 * Your Task:
 * You do not need to take input or print anything. Your task is to complete the function matrixMultiplication() 
 * which takes the value N and the array arr[] as input parameters and returns the minimum number of multiplication operations needed to be performed.
 *
 * Expected Time Complexity: O(N^3)
 * Expected Auxiliary Space: O(N^2)
 *
 * Constraints:
 * 2 ≤ N ≤ 100
 * 1 ≤ arr[i] ≤ 500
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> dp;

// Top-Down Approach
int matrixMultiplication(vector<int> &arr, int i, int j){
    // base case
    if(i >= j) return 0;
    if(i+1 == j) return 0;


    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k=i+1; k<=j-1; k++){
        ans = min(ans, matrixMultiplication(arr, i, k) + matrixMultiplication(arr, k, j) + arr[i]*arr[k]*arr[j]);
    }

    return dp[i][j] = ans;
}

// Bottom-Up Approach
int matrixMultiplicationBU(vector<int> &arr){
    int N = arr.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // for(int len=3; len<=N; len++){
    //     for(int i=0; i<=N-len; i++){
    //         int j = i + len - 1;
    //         dp[i][j] = INT_MAX;
    //         for(int k=i+1; k<=j-1; k++){
    //             dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
    //         }
    //     }
    // }
    // return dp[0][N-1];

    for(int i=N-3; i>=0; i--){
        for(int j=i+2; j<N; j++){
            dp[i][j] = INT_MAX;
            for(int k=i+1; k<=j-1; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    return dp[0][N-1];
}

int main(){
    vector<int> arr = {40, 20, 30, 10, 30};
    int N = arr.size();

    dp.clear();
    dp.resize(N, vector<int>(N, -1));

    // cout << matrixMultiplication(arr, 0, N-1) << endl;
    cout << matrixMultiplicationBU(arr) << endl;
    return 0;
}