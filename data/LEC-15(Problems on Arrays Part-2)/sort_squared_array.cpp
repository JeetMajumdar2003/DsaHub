#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Sorting: O(n^2)
    int arr[] = {-10,-5,3,6,7};
    for (int i = 0; i < 5; i++){
        for (int j = i; j < 5; j++){
            if (abs(arr[i])>abs(arr[j])){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        arr[i]*=arr[i];
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Using Two Pointers:  O(n)
    vector<int> v{-10,-7,-3,2,5,6}, v1(6);
    int left = 0;
    int right = 5;
    int i=0;
    while (left<=right){
        if (abs(v[left])>abs(v[right])){
            v1[i]=v[left]*v[left];
            left++;
        }
        else{
            v1[i]=v[right]*v[right];
            right--;
        }
        // else if(abs(v[left])<abs(v[right])){
        //     v1[i]=v[right]*v[right];
        //     right--;
        // }
        // else if (abs(v[left])==abs(v[right])){
        //     v1[i]=v[right]*v[right];
        //     right--;
        // }
        i++;
    }
    reverse(v1.begin(), v1.end());
    for (int ele:v1)
    {
        cout<<ele<<" ";
    }
    
    return 0;
}