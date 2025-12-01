#include <iostream>
using namespace std;

int main()
{
    int x = 25;
    float y= 75.5;

    // Create a pointer variable with the address of x;
    // As x is an integer, so we need to use a pointer that can store address of an integer type.
    // So we use int* to declare a pointer variable.
    int* ptr = &x;  // int *ptr; int * ptr are also valid.
    cout<<"Address of x = "<<ptr<<endl;

    // Create a pointer variable with the address of y;
    // As y is a float, so we need to use a pointer that can store address of a float type.
    // So we use float* to declare a pointer variable.
    float* ptr1 = &y;  // float *ptr1; float * ptr1 are also valid.
    cout<<"Address of y = "<<ptr1<<endl;
    return 0;
}