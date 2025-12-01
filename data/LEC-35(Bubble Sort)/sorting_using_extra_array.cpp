#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2,5,1,4,3};
    int sortedArr[5], j;
    int min = INT_MAX;
    for (int i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if(arr[j]<min){
                min = arr[j];
            }
        }
        sortedArr[i]=min;
    }
    for (int i = 0; i < 5; i++){
        cout<<sortedArr[i]<<" ";
    }
    
    return 0;
}