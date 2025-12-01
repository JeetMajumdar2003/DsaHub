#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[] = {1,2,5,6,4};
    int even_sum = 0, odd_sum = 0;
    for(int i=0; i<5; i++)
    {
        if(i%2 == 0)
            even_sum += array[i];
        else
            odd_sum += array[i];
    }
    cout<<"Difference between sum of even and odd indices: "<<even_sum - odd_sum<<endl; // 2

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        if (i%2==0)
            sum+=array[i];
        else
            sum-=array[i];
    }
    cout<<"Difference: "<<sum; // 2
    return 0;
}