#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Integer input
    int apples;
    cout << "Enter the number of apples you have: ";
    cin >> apples;
    cout << "You have " << apples << " apples." << endl;

    // String input
    string name;
    cout << "Enter your name: ";

    // cin >> name; // This will only read the first word
    // cin >> name;
    // cout << "Hello " << name << endl;

    // Clear the newline character from the input stream
    cin.ignore();

    // To read the entire line, use getline() function
    getline(cin, name);
    cout << "Hello " << name << endl;
    
    return 0;
}