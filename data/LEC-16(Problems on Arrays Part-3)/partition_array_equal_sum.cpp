#include <iostream>
using namespace std;

bool check_partition(int arr[], int& n){
    int total_sum = 0;
    for (int i = 0; i < n; i++){
        total_sum+=arr[i];
    }
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum+=arr[i];  // Calculating prefix sum
        int suffix_sum = total_sum - prefix_sum;    // Calculating suffix sum
        if (prefix_sum == suffix_sum){
            return true;
        }
    }
    return false;
}

int main()
{
    // Checking Total sum: (My Method)
    int a[] = {1,2,6,5,8,3,9,7,4,5}, sum=0;
    for (int i = 0; i < 10; i++){
        sum+=a[i];
    }
    cout<<sum<<endl;
    int i=0;
    int pre_sum = 0;
    while (1){
        pre_sum+=a[i];
        if (pre_sum==sum/2){
            cout<<"partition possible"<<endl;
            break;
        }
        else{
            if (i==9){
                cout<<"partition not possible"<<endl;
                break;
            }
        }
        i++;
    }

    // Method-2: (Using Prefix sum and suffix sum) Suffix sum(i+1) = Total sum - Prefix sum(i)
    int arr[] = {1,2,6,5,7,4,9,7,4,5};
    int total_sum = 0;
    for (int i = 0; i < 10; i++){
        total_sum+=arr[i];
    }
    cout<<total_sum<<endl;
    int prefix_sum = 0;
    for (int i = 0; i < 10; i++)
    {
        prefix_sum+=arr[i];  // Calculating prefix sum
        int suffix_sum = total_sum - prefix_sum;
        if (prefix_sum == suffix_sum){
            cout<<true;
            break;
        }
        else{
            if (i==9){
                cout<<false;
                break;
            }
        }
    }
    cout<<endl;

    // Method-3: (Using Function)
    int arr1[] = {1,2,6,5,7,4,9,7,4,5};
    int n = 10;
    cout<<check_partition(arr1, n);

    return 0;
}