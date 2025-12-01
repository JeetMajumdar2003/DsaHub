#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter a number: ";
    cin >> a;

    // if statement:
    if (a > 0){
        cout << "The number is positive." << endl;
    }

    // if-else statement:
    if (a > 0){
        cout << "The number is positive." << endl;
    }
    else{
        cout << "The number is negative." << endl;
    }

    // if-else-if statement:
    if (a > 0){
        cout << "The number is positive." << endl;
    }
    else if (a < 0){
        cout << "The number is negative." << endl;
    }
    else{
        cout << "The number is zero." << endl;
    }
    return 0;
}