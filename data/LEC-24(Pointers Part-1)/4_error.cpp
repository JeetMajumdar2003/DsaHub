#include <iostream>
using namespace std;

int main()
{
    float x = 25.5;

    // int* ptr = &x;
    float* ptr = &x;

    cout<<"Address of x = "<<ptr<<endl;
    return 0;
}