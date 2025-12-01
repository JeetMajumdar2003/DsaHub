#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter a number: ";
    cin >> a;
    
    // Nested if-else statement:
    if (a != 0){
        if (a > 0){
            cout << "The number is positive." << endl;
        }
        else{
            cout << "The number is negative." << endl;
        }
    }
    else{
        cout << "The number is Zero." << endl;
        
    }
    return 0;
}