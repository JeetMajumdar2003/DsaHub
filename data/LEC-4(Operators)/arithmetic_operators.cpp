#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout<<"Enter Two numbers: ";
    cin>>num1>>num2;

    // Addition Operator:
    int add = num1 + num2;
    cout<<"Addition of two numbers is: "<<add<<endl;

    // Subtraction Operator:
    int sub = num1 - num2;
    cout<<"Subtraction of two numbers is: "<<sub<<endl;

    // Multiplication Operator:
    int mul = num1 * num2;
    cout<<"Multiplication of two numbers is: "<<mul<<endl;

    // Division Operator:
    int div = num1 / num2;
    cout<<"Division of two numbers is: "<<div<<endl;

    // Modulus Operator:
    int mod = num1 % num2;
    cout<<"Modulus of two numbers is: "<<mod<<endl;

    // Increment Operator:
    cout<<"Pre Increment of num1 is: "<<++num1<<endl;   // Pre Increment Operator
    cout<<"Post Increment of num2 is: "<<num2++<<endl;   // Post Increment Operator

    // Decrement Operator:
    cout<<"Pre Decrement of num1 is: "<<--num1<<endl;   // Pre Decrement Operator
    cout<<"Post Decrement of num2 is: "<<num2--<<endl;   // Post Decrement Operator

    return 0;
}