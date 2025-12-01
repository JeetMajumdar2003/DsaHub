#include <iostream>
using namespace std;

int main()
{
    int x = 10; // local variable to main()
    cout << "Value of x in main() = " << x << endl;
    {
        int x = 20; // local variable to inner block
        cout << "Value of x in inner block = " << x << endl;
    }
    cout << "Value of x in main() = " << x << endl;
    return 0;
}