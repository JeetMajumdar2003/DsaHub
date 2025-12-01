#include <iostream>
using namespace std;

// call by reference using reference variables(where we create a reference variable and pass it as an argument to the function)
// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

// call by reference using pointers(where we create a pointer variable and pass it as an argument to the function)
void swap(int *a, int *b){
    int temp = *a; // temp = 10
    *a = *b;       // a = 20
    *b = temp;     // b = 10
}

int main()
{
    int a = 10, b = 20;
    cout << "Before swapping: ";
    cout << "a = " << a << ", b = " << b << endl;

    // Pointer variable stores the address of the variable
    int *ptr1 = &a;
    int *ptr2 = &b;

    // Swap Function called
    swap(ptr1, ptr2);

    cout << "After swapping: ";
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}