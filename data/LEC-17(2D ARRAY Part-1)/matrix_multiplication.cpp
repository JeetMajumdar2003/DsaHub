#include <iostream>
using namespace std;

int main()
{
    int r1, c1, r2, c2;
    cout<<"Enter Rows of array1: ";
    cin>>r1;
    cout<<"Enter Columns of array1: ";
    cin>>c1;
    cout<<"Enter Rows of array2: ";
    cin>>r2;
    cout<<"Enter Columns of array2: ";
    cin>>c2;
    int array1[r1][c1], array2[r2][c2];
    // Check if multiplication possible or not: c1=r2
    if (c1!=r2){
        cout<<"Matrix Multiplication not possible.";
        return 0;
    }

    // Taking input elements:
    // For Array1:
    cout<<"Enter Inputs of array1: ";
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            cin>>array1[i][j];
        }
    }
    // For Array2:
    cout<<"Enter Inputs of array2: ";
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            cin>>array2[i][j];
        }
    }
    
    // Multiply Two arrays:
    int ans[r1][c2];
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            int temp=0;
            for (int k = 0; k < c1; k++){
                temp = temp + array1[i][k]*array2[k][j];
            }
            ans[i][j] = temp;
        }
    }
    // print ans array:
    cout<<"Multiplication of these two arrays is: "<<endl;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}