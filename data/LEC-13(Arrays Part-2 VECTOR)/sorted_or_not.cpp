#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[] = {1,2,3,4,5};
    bool sorted = 1;
    for (int i = 1; i < 5; i++){
        if (array[i]<=array[i-1]){
            sorted = 0;
            break;
        }
    }
    if (sorted==1)
        cout<<"Sorted array";
    else
        cout<< "Unsorted array";
    return 0;
}