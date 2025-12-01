#include <iostream>
using namespace std;

int main()
{
    int num1 = 6, num2 = 8;

    // Unary Plus Operator:
    cout<<"Unary Plus Operator on num1 is: "<<+num1<<endl;

    // Unary Minus Operator:
    cout<<"Unary Minus Operator on num1 is: "<<-num1<<endl;

    // Logical NOT Operator:
    cout<<"Logical NOT Operator on num1 is: "<<!num1<<endl;

    // Bitwise NOT Operator:
    cout<<"Bitwise NOT Operator on num1 is: "<<~num1<<endl;

    // Increment Operator:
    cout<<"Pre Increment of num1 is: "<<++num1<<endl;   // Pre Increment Operator
    cout<<"Post Increment of num2 is: "<<num2++<<endl;   // Post Increment Operator

    // Now num1 = 7 and num2 = 9
    cout<<"num1 is: "<<num1<<endl;
    cout<<"num2 is: "<<num2<<endl;

    // Decrement Operator:
    cout<<"Pre Decrement of num1 is: "<<--num1<<endl;   // Pre Decrement Operator
    cout<<"Post Decrement of num2 is: "<<num2--<<endl;   // Post Decrement Operator

    // Now num1 = 6 and num2 = 8
    cout<<"num1 is: "<<num1<<endl;
    cout<<"num2 is: "<<num2<<endl;

    // NaN (Not a Number):
    cout<<"NaN is: "<<num1 / 0<<endl;

    return 0;
}