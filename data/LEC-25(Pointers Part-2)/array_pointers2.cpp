#include <iostream>
using namespace std;

// Call by reference
void process(int *arr, int n){
    // inside this function we have the access of the same array in the main
    for (int i = 0; i < n; i++){
        cout<<*(arr+i)<<" ";
    } cout<<endl; 
    *(arr+1) = 10;
}

// void process(int arr[], int n){
//     // inside this function we have the access of the same array in the main
//     for (int i = 0; i < n; i++)
//     {
//         cout<<(arr[i])<<" ";
//     }
// }

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    process(array, 9);

    for (int i = 0; i < 9; i++){
        cout<<*(array+i)<<" ";
    }
    return 0;
}