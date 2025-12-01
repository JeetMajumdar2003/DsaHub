#include <bits/stdc++.h>
using namespace std;

// Transpose the matrix and then reverse the row: for square matrix
void rotateMatrix(vector<vector<int>> &v){
    int n = v.size();
    // Transpose the matrix:
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){    // j < i because we only need to swap the lower triangle matrix
            swap(v[i][j], v[j][i]);
        }
    }
    // Reverse the row:
    for (int i = 0; i < n; i++){
        reverse(v[i].begin(), v[i].end());
    }
}

int main()
{
    int n, m;
    cout<<"Enter no of Rows: ";
    cin>>n;
    cout<<"Enter no of Columnss: ";
    cin>>m;
// taking input:
    int matrix[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>matrix[i][j];
        } 
    }
    // Print the matrix:
    cout<<"Matrix: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    // Print the Rotate Matrix(90 degree): Without using new array
    cout<<"Rotate Matrix(90 degree): "<<endl;
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            cout<<matrix[n-1-i][j]<<" ";
        }
        cout<<endl;
    }

    // Print the Rotate Matrix(90 degree):using new array
    cout<<"Rotate Matrix(90 degree) Creating new matrix: "<<endl;
    int rotatematrix[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            rotatematrix[i][j] = matrix[n-1-j][i];
            cout<<rotatematrix[i][j]<<" ";
        }
        cout<<endl;
    }

    // using vector: rotateMatrix function:
    int r;
    cin>>r;
    vector<vector<int>> v(r, vector<int>(r));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < r; j++){
            cin>>v[i][j];
        }
    }
    rotateMatrix(v);
    cout<<"Rotate Matrix(90 degree) Using vector: "<<endl;
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}