#include <iostream>
using namespace std;

void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << " b = " << b << endl;
    swap(a, b); // call by value copy of a and b is passed
    cout << "After swap: a = " << a << " b = " << b << endl;

    return 0;
}