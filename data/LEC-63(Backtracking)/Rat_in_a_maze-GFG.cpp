/*
#include <iostream>
#include <vector>
using namespace std;

vector<string> ans; // Vector to store all possible paths

void solve(int i, int j, int n, int m, string s, vector<vector<int>>& vis, vector<vector<int>>& mat){
    // Base case: If the current position is out of bounds or already visited or blocked, return
    if(i<0 or j<0 or i>n-1 or j>m-1 or vis[i][j]==1 or mat[i][j]==0) return;
    
    // If we have reached the destination, add the path to the answer vector and return
    if(i==n-1 and j==m-1){
        ans.push_back(s);
        return;
    }
    
    // Recursive case:
    vis[i][j]=1;    // Mark the current index as visited
    
    // Call for down(D) move
    solve(i+1, j, n, m, s+'D', vis, mat);
    // Call for up(U) move
    solve(i-1, j, n, m, s+'U', vis, mat);
    // Call for right(R) move
    solve(i, j+1, n, m, s+'R', vis, mat);
    // Call for left(L) move
    solve(i, j-1, n, m, s+'L', vis, mat);
    
    // Backtrack: Mark the current index as unvisited
    vis[i][j]=0;
    
    return;
}

vector<string> findPath(vector<vector<int>> &mat) {
    int n=mat.size();
    int m=mat[0].size();
    if(mat[0][0]==0) return {"-1"}; // If the starting position is blocked, return "-1"
    vector<vector<int>> vis(n, vector<int>(m,0)); // Create a 2D vector to keep track of visited positions
    solve(0,0,n,m,"",vis,mat); // Call the recursive function to find all possible paths
    return ans; // Return the answer vector
}

int main(){
    vector<vector<int>> mat =  {{1, 0, 1, 1},
                                {1, 1, 1, 1},
                                {1, 0, 0, 1},
                                {1, 1, 1, 1}};
    vector<string> res = findPath(mat); // Find all possible paths in the given matrix
    for(auto x: res){
        cout<<x<<endl; // Print each path
    }
    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> ans; // Vector to store all possible paths

void solve(int i, int j, int n, int m, string s, vector<vector<int>>& vis, vector<vector<int>>& mat){
    if(i<0 or j<0 or i>n-1 or j>m-1 or vis[i][j]==1 or mat[i][j]==0) return;
    if(i==n-1 and j==m-1){
        ans.push_back(s);
        return;
    }
    vis[i][j]=1;
    solve(i+1, j, n, m, s+'D', vis, mat);
    solve(i-1, j, n, m, s+'U', vis, mat);
    solve(i, j+1, n, m, s+'R', vis, mat);
    solve(i, j-1, n, m, s+'L', vis, mat);
    vis[i][j]=0;
    return;
}

vector<string> findPath(vector<vector<int>> &mat) {
    ans.clear();
    int n=mat.size();
    int m=mat[0].size();
    if(mat[0][0]==0) return {"-1"};
    vector<vector<int>> vis(n, vector<int>(m,0));
    solve(0,0,n,m,"",vis,mat);
    return ans.empty() ? vector<string>{"-1"} : ans;
}

void runTestCases() {
    vector<vector<vector<int>>> testCases = {
        {{1, 0, 1, 1}, {1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}},
        {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
        {{1}},
        {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}, {1, 0, 1, 1}},
        {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}},
        {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 0}}
    };

    vector<vector<string>> expectedOutputs = {
        {"DDDRRR", "DRRURDDD", "DRRRDD",},
        {"-1"},
        {""},
        {"DDRRDR", "DDRRRD", "RRRDDD", "RRRDDLDR"},
        {"-1"},
        {"-1"}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        vector<string> result = findPath(testCases[i]);
        cout << "Test Case " << i + 1 << ": ";
        if (result == expectedOutputs[i]) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            cout << "Expected: ";
            for (const auto& path : expectedOutputs[i]) {
                cout << path << " ";
            }
            cout << endl;
            cout << "Got: ";
            for (const auto& path : result) {
                cout << path << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    runTestCases();
    return 0;
}
