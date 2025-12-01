#include <iostream>
using namespace std;

int main()
{
    int age;
    cout<<"Enter your age: ";
    cin >> age;

    // Not a good code
    // if(age<12)
    //     cout<<"Child";
    // else if(age>=12 && age <18)  // logical operator
    //     cout<<"Teenager";
    // else if(age>=18)
    //     cout<<"Adult";

    // Improved Code
    if(age>=18)
        cout<<"Adult";
    else if(age>=12)
        cout<<"Teenager";
    else
        cout<<"Child";
    return 0;
}