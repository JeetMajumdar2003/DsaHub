#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2, 5, 8, 10, 15, 13, 19, 20, 23, 25}, n;
    cout << "Enter the number you want to search(0-25): ";
    cin >> n;

    // Linear Search Algorithm
    int ans = -1;
    for (int i = 0; i < 10; i++){
        if (arr[i] == n){
            ans = i;
            break;
        }
    }
    cout << "The index of the number is: " << ans << endl;

    // M-2
    for(int i=0; i<10; i++){
        if(arr[i]==n){
            cout << "The index of the number is: " << i << endl;
            break;
        }
        else if (i==9){
            cout << "The number is not present in the array" << endl;
        }
    }

    // M-3
    int isPresent = 0;
    for(int i=0; i<10; i++){
        if(arr[i]==n){
            cout << "The index of the number is: " << i << endl;
            isPresent = 1;
            break;
        }
    }
    if(isPresent==0){
        cout << "The number is not present in the array" << endl;
    }
    return 0;
}