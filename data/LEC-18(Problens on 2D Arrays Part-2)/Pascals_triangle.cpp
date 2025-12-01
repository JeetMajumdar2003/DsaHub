#include <bits/stdc++.h>
using namespace std;

// Fcatorial:
int fact(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

// Using 2D vector function:
vector<vector<int>> pascalTriangle(int numRows)
{
    vector<vector<int>> pascal;
    for (int i = 0; i < numRows; i++){
        vector<int> row(i+1, 1);
        for (int j = 1; j < i; j++){
            row[j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
        pascal.push_back(row);
    }
    return pascal;

    // // Withut creating extra row Array:
    // vector<vector<int>> pascal(numRows);
    // for (int i = 0; i < numRows; i++){
    //     pascal[i].resize(i + 1);
    //     for (int j = 0; j < i + 1; j++){
    //         if (j == 0 || j == i){
    //             pascal[i][j] = 1;
    //         }
    //         else{
    //             pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    //         }
    //     }
    // }
    // return pascal;
}

int main()
{
    // Using Combinatorics:(nCr)
    // int n;
    // cout << "Enter the number of rows: ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << fact(i) / (fact(j) * fact(i - j)) << " ";
    //     }
    //     cout << endl;
    // }

    // Using 2D vector:
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;
    vector<vector<int>> ans;
    ans = pascalTriangle(numRows);
    // Printing the vector:
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}