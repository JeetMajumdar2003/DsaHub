#include <iostream>
using namespace std;

void makeTwise(int p){
    p = p * 2;
    cout << "formal p = " << (p) << endl;
}

int main()
{
    int p = 25;
    makeTwise(p);
    cout << "Actual p = " << (p);
    return 0;
}