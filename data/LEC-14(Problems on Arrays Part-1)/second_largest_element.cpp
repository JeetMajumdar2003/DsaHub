#include <bits/stdc++.h>
using namespace std;

// find max index
int maxIndex(int array[], int size){
    int maxidx = -1, max = INT_MIN;
    for (int i = 0; i < size; i++){
        if(array[i]>max){
            maxidx = i;
            max=array[i];
        }
    }
    return maxidx;
}

// print array
void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1,5,6,4,89,7,16,3};
    
    // Method-1(First Finding Index of Max element)
    int midx=0, max=INT_MIN;
    for (int i = 0; i < 8; i++){
        if (arr[i]>max){
            midx=i;
            max=arr[i];
        }
    }
    cout<<"Max: "<<max<<endl;   // 89
    arr[midx]=-1;
    int s_max=INT_MIN;
    for (int i = 0; i < 8; i++){
        if (arr[i]>s_max)
            s_max=arr[i];
    }
    cout<<"Second max: "<<s_max<<endl;  // 16

    // Methode: 2(First Finding Max element)
    int arr2[] = {45,6,9,7,5,4,3,65};
    int max2 = INT_MIN;
    int smax = INT_MIN;
    for (int i = 0; i < 8; i++){
        if (max2 < arr2[i])
            max2 = arr2[i];
    }
    cout<<"Max: "<<max2<<endl;  // 65
    for (int i = 0; i < 8; i++){
        if (arr2[i]!=max2 && smax<arr2[i])
            smax = arr2[i];
    }
    cout<<"Second max: "<<smax<<endl;   // 45

    // Method-3(using function):
    int arr3[] = {55,1,6,60,9,8,4,6,9,5};
    int maxidx = maxIndex(arr3, 10);
    arr3[maxidx] = -1;
    int smaxidx = maxIndex(arr3, 10);
    cout<<"Second Max: "<<arr3[smaxidx]<<endl; // 55

    // Method-4(assending and decending order array elements)
    int arr4[] = {1,2,3,5,4};
    int max4 = INT_MIN;
    int smax4 = INT_MIN;
    for (int i = 0; i < 5; i++)
    {
        // for assending order array elements
        if (max4<arr4[i]){
            smax4=max4;   // 2nd max
            max4 = arr4[i]; // 1st max
        }
        // for decending order array elements
        else if (max4>arr4[i] && smax4<arr4[i]){
            smax4=arr4[i];  // 2nd max
        }
    }
    cout<<"Second Max: "<<smax4<<endl;  // 4

    // Method-5(for duplicate elements)
    int arr5[] = {1,2,3,5,6,5,6,5,4};
    int maxidx5 = maxIndex(arr5, 9);
    int largestElement = arr5[maxidx5];
    printArray(arr5, 9);
    cout<<"Max: "<<largestElement<<endl;    // 6
    // if we dont use extra variable then, when you replace the first 6 with -1, the value of arr5[4] changes to -1 as well. This means that in the next iteration, you are comparing each element with -1, which is the new value of arr5[4]
    for (int i = 0; i < 9; i++){
        if (arr5[i]==largestElement){   // if we use arr5[i]==arr5[maxidx5] then it will not work
            arr5[i]=-1;
            cout<<"Max idx: "<<i<<endl;
        }
    }
    printArray(arr5, 9);
    int smaxidx5 = maxIndex(arr5, 9);
    cout<<"Second Max: "<<arr5[smaxidx5]<<endl; // 5
    return 0;
}