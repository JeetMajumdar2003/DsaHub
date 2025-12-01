#include <iostream>
using namespace std;

int main()
{
    // Using Two Pointer:
    int arr[] = {5,9,4,6,3,4,2,5,11,8};
    int left = 0;
    int right = 9;
    while (left<right){
        if (arr[left]%2==1 && arr[right]%2==0){
            int temp = arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
        else if (arr[left]%2==0){
            left++;
        } 
        else if (arr[right]%2==1){
            right--;
        }   
    }
    for (int i = 0; i < 10; i++)
        cout<<arr[i]<<" ";
    return 0;
}