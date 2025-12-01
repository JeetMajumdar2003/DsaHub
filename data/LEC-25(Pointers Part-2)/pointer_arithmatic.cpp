#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    double b = 20.0;
    int *ptr = &a;
    double *ptr2 = &b;

    cout<<"Size of a: "<<sizeof(a)<<endl;   // 4
    cout<<"Size of ptr: "<<sizeof(ptr)<<endl;   // 8
    cout<<"Size of b: "<<sizeof(b)<<endl;   // 8
    cout<<"Size of ptr2: "<<sizeof(ptr2)<<endl;  // 8

    cout << (ptr-1)<< " " << ptr << " " << (ptr+1)<< " " << (ptr+2) << endl;
    cout << (ptr2-1)<< " "  << ptr2 << " " << (ptr2+1)<< " " << (ptr2+2) << endl;
    return 0;
}

/**
 * (ptr+i) = ptr + i*sizeof(*ptr)
*/