#include <iostream>
using namespace std;

int main()
{
    // for loop structure:
    /*
    for (initialization; condition; increment/decrement)
    {
        // body of the loop
    }*/

    cout<<"<-----Omitting Initialization----->"<<endl;
    // Omitting Initialization:
    int i = 1;
    for (   ; i <= 5; i++)
        cout << i << endl;

    cout<<"<-----Omitting Condition----->"<<endl;
    // Omitting Condition:
    for (int i = 10; ; i++)
    {
        cout << i << endl;
        if (i == 15)
            break;
    }

    cout<<"<-----Omitting Increment/Decrement----->"<<endl;
    // Omitting Increment/Decrement:
    for (int i = 20; i <= 25; )
    {
        cout << i << endl;
        i++;
    }

    cout<<"<-----Having more than two variables inside a for loop----->"<<endl;
    // Having more than two variables inside a for loop:
    for (int i = 1, j = 10; i <= 5; i++, j--)
        cout << i << " + " << j << " = " <<i+j<< endl;
    return 0;
}