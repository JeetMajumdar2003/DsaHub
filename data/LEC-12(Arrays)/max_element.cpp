#include <iostream>
// #include <cmath>
using namespace std;

int main()
{
    int arr[] = {45, 89, 53, 1, 56}, max = arr[0]; // max = INT_MIN or -INFINITY or -1e9 or -1*pow(10,9) or -2147483648
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int idx = 0; idx < size; idx++){
        if (arr[idx] > max){
            max = arr[idx];
        }
    }
    cout<< "Max element in array is: "<<max<<endl;
    return 0;
}