#include <iostream>
using namespace std;

int main()
{
    // Address of Pointer Variable:
    int x = 10;
    int *ptr = &x;

    cout<<"Address of x = "<<&x<<endl;
    cout<<"Address stored in ptr = "<<ptr<<endl;
    cout<<"Address of ptr itself = "<<&ptr<<endl;

    return 0;
}