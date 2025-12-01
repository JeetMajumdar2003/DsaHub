#include <iostream>
using namespace std;

int main()
{
    int x = 60, y = 90;
    if (y % x == 0)
        cout << "Good\n";
    else if (y-x == 30)
        cout << "Neutral\n";
    else
        cout << "Bad\n";
    return 0;
}