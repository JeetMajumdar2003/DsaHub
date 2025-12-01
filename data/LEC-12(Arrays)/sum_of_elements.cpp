#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 54, 7, 3, 9}, sum = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int idx = 0; idx < size; idx++){
        sum+=arr[idx];
    }
    cout<< "Sum of elements in array is: "<<sum<<endl;
}