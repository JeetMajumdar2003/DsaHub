#include <bits/stdc++.h>
using namespace std;

// spiral order traversal of a matrix
void spiralOrder(vector<vector<int>>& matrix) {
    int top = 0;
    int bottom = matrix.size()-1;
    int left = 0;
    int right = matrix[0].size()-1;
    int direction = 0;

    while (top <= bottom && left <= right)
    {
        // left -> right
        if (direction == 0){
            for (int col = left; col <= right; col++){
                cout << matrix[top][col] << " ";
            }
            top++;
        }
        
        // top -> bottom
        else if (direction == 1){
            for (int row = top; row <= bottom; row++){
                cout << matrix[row][right] << " ";
            }
            right--;
        }

        // right -> left
        else if (direction == 2){
            for (int col = right; col >= left; col--){
                cout << matrix[bottom][col] << " ";
            }
            bottom--;
        }

        // bottom -> top
        else if (direction == 3){
            for (int row = bottom; row >= top; row--){
                cout << matrix[row][left] << " ";
            }
            left++;
        }

        // change direction after each traversal
        direction = (direction + 1) % 4;
    }
    
}

int main()
{
    int n,m;
    cout<<"Enter the number of rows: ";
    cin>>n;
    cout<<"Enter the number of columns: ";
    cin>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout<<"Enter the elements of the matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    
    spiralOrder(matrix);
    return 0;
}

// dry run
// 1 2 3
// 4 5 6
// 7 8 9

// left = 0, right = 2
// top = 0, bottom = 2
// direction = 0

// ans = 1 2 3 6 9 8 7 4 5