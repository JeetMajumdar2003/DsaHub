#include <iostream>
using namespace std;

int main()
{
    // Method 1: Traversing the array: O(n)
    int array[] = {0,1,1,0,1,0,0,1};
    for (int  i = 0; i < 8; i++){
        for (int j = i+1; j < 8; j++){
            int temp = array[i];
            if (array[i] > array[j]){
                array[i]  = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < 8; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    // Method 2: Counting the number of 0's and 1's: O(n)
    int array1[] = {1,1,0,1,1,0,1,0};
    int count_0 = 0;
    for (int i = 0; i < 8; i++){
        if (array1[i] == 0){
            count_0++;
        }
    }
    for (int i = 0; i < 8; i++){
        if (i < count_0)
            array1[i] = 0;
        else
            array1[i] = 1;
    }
    for (int i = 0; i < 8; i++)
        cout<<array1[i]<<" ";
    cout<<endl;

    // Using Two Pointers: O(n)
    int array2[] = {1,0,0,1,0,0,1,0};
    int left = 0;
    int right = 7;
    while (left<=right){
        if (array2[left]==1 && array2[right]==0){
            array2[left]=0;
            array2[right]=1;
            left++;
            right--;
        }
        else if (array2[left]==0){
            left++;
        } 
        else if (array2[right]==1){
            right--;
        }   
    }
    for (int i = 0; i < 8; i++)
        cout<<array2[i]<<" ";
    return 0;
}