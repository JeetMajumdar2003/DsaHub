#include <iostream>
using namespace std;

int main()
{
    int array[] = {1,2,6,5,4,8,3,7,4,9};
    int x, pairs=0;
    cout<<"Enter x: ";
    cin>>x;
    for (int i = 0; i < 10; i++){
        for (int j = i+1; j < 10; j++){
            if (array[i]+array[j]==x)
                pairs++;
        }
    }
    cout<<"Total No. of pairs is: "<<pairs;
    return 0;
} 