#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *ptr = &x;
    
    cout<<"Address stored in ptr = "<<ptr<<endl;
    cout<<"Value present at the address ptr is *ptr = "<<*ptr<<endl;

    // Updating the value of x
    x = 20;
    cout<<"Updated value of x = "<<x<<endl;
    cout<<"New value of *ptr = "<<*ptr<<endl;

    // Updating the value of x using pointer
    *ptr = 30;
    cout<<"Updated value of x = "<<x<<endl;
    cout<<"New value of *ptr = "<<*ptr<<endl;

    int valueAtX = *ptr;
    cout<<"Value at x = "<<valueAtX<<endl;
    return 0;
}