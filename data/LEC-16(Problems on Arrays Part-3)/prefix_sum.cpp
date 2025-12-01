#include <iostream>
using namespace std;

int main()
{
    // Method-1(Using Extra Variable)
    int array[] = {5,4,2,1,3};
    int prefix_sum = 0;
    for (int i = 0; i < 5; i++){
        prefix_sum+=array[i];
        array[i] = prefix_sum;
        cout<<array[i]<<" ";
    }
    cout<<endl;

    // Method-2(Without Using Extra Variable)
    int arr[] = {4,5,6,1,3};
    for (int i = 0; i < 5; i++){
        arr[i] = arr[i-1] + arr[i]; 
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}