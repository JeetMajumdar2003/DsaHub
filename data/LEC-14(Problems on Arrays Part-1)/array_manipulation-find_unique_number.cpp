#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2,3,1,4,3,2,1};
    for (int i = 0; i < 7; i++)
    {
        for (int j = i+1; j < 7; j++){
            if (arr[i]==arr[j]){
                arr[i]=arr[j]=-1;
            }
        }
        if (arr[i]>=0){
            cout<<"Unique element is: "<<arr[i];
        }
    }
    return 0;
}