#include <iostream>
using namespace std;

int main()
{
    int x = 2;
    switch (x){
        case 1:
            cout << "Java\n";
        case 2:
            cout << "CPP\n";
        default:
            cout << "PYTHON\n";
    }
    return 0;
}