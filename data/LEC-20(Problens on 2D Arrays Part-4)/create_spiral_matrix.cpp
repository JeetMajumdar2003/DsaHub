#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a positive Integer: ";
    cin>>n;
    int matrix[n][n];
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = n-1;
    int direction = 0;
    int value = 1; // value to be filled in the matrix

    while (top <= bottom && left <= right)
    {
        // left -> right
        if (direction == 0){
            for (int col = left; col <= right; col++){
            matrix[top][col] = value++;;
            }
            top++;
        }
        
        // top -> bottom
        else if (direction == 1){
            for (int row = top; row <= bottom; row++){
            matrix[row][right] = value++;;
            }
            right--;
        }

        // right -> left
        else if (direction == 2){
            for (int col = right; col >= left; col--){
            matrix[bottom][col] = value++;;
            }
            bottom--;
        }

        // bottom -> top
        else if (direction == 3){
            for (int row = bottom; row >= top; row--){
                matrix[row][left] = value++;;
            }
            left++;
        }

        // change direction after each traversal
        direction = (direction + 1) % 4;
    }

    // print the matrix
    cout << "The matrix is: " << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Sample Input/Output:
// Enter a positive Integer: 3

// top = 0, bottom = 2;
// left = 0, right = 2;
// direction = 0;
// value = 1

// The matrix is:
// 1 2 3
// 8 9 4
// 7 6 5