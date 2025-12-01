#include<iostream>
using namespace std;

int x = 10; // global variable

int main()
{
    cout << "Value of x in main() = " << x << endl;
    int x = 20; // local variable to main()
    cout << "Value of x in main() = " << x << endl;
    {
        cout << "Value of x in inner block = " << x << endl;
        int x = 30; // local variable to inner block
        cout << "Value of x in inner block = " << x << endl;
    }
    cout << "Value of x in main() = " << x << endl;

    cout << "Value of global x = " << ::x << endl; // global x using scope resolution operator(::)

    return 0;
}