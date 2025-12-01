#include <iostream>
using namespace std;

void temp(int p){
    int q = p;
    q = p - 100;
}

int main()
{
    int p = 890;
    temp(p);
    // cout << (q);  // q is not defined in this scope (main) because it is defined in the scope of temp function, so it throws an error
    return 0;
}