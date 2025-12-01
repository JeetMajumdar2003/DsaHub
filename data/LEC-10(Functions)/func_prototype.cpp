#include <iostream>
using namespace std;

// Function prototype
void welcome();
int multiply(int, int);  // int multiply(int x, int y);

int main()
{
    welcome();
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Product = " << multiply(a, b) << endl;
    return 0;
}

void welcome()
{
    cout << "Welcome to C++ Programming by PW Skills!" << endl;
}

int multiply(int x, int y)
{
    return x * y;
}
