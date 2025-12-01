#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cout<<"Enter Rows of matrix: ";
    cin>>r;
    cout<<"Enter Columns of matrix: ";
    cin>>c;
    int array[r][c];
    cout<<"Enter Inputs of matrix: ";
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin>>array[i][j];
        }
    }
    cout<<"actual matrix is: "<<endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Transpose of the matrix is: "<<endl;
    int transpose[c][r];
    for (int i = 0; i < c; i++){
        for (int j = 0; j < r; j++){
            transpose[i][j] = array[j][i];
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}