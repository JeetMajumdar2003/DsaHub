#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10,20,30,40,50};

    int *ptr2 = (arr+2);
    cout<<*ptr2<<endl;

    *ptr2++;
    cout<<*ptr2<<endl;

    *ptr2--;
    cout<<*ptr2<<endl;
    return 0;
}