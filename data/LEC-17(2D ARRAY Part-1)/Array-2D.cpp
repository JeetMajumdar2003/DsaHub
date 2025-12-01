#include <iostream>
using namespace std;

int main()
{
    // Declaration of 2D Array:
    int array[2][3];

    // Initialization of 2D Array:
    int array2[2][3] = {1,2,3,4,5,6};

    // Taking Input:
    int n,m;
    cout<< "Enter Row Number: ";
    cin>>n;
    cout<< "Enter Column Number: ";
    cin>>m;
    int array2D[n][m];
    // Taking input using 2 for loops:
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<"Enter elelment: ";
            cin>>array2D[i][j];
        }
    }
    // Print The 2d Array:
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<array2D[i][j]<<" ";
        }
    }
    
    return 0;
}