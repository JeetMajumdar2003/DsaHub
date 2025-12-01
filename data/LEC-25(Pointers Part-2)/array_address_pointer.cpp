#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10,20,30,40,50};
    int (*ptr)[5] = &arr;
    cout<<ptr<<" "<<arr<<" "<<*ptr<<" "<<*arr;
    return 0;
}