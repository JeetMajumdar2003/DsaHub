#include <iostream>
using namespace std;

int main()
{
    int x = 10, y = 20;
    int *ptrx = &x;

    // ptr = 5; // This is wrong. We cannot assign a value to a pointer like this.

    // *ptrx = &y; // This is wrong. We cannot assign an address to a int variable like this.

    return 0;
}