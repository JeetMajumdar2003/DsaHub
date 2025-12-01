#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout<<"Enter Two Numbers: ";
    cin>>num1>>num2;

    // Assignment Operator:
    cout<<"\nAssignment Operator: "<<endl;
    cout<<"num1 = num2 is: num1 = "<<(num1 = num2)<<endl;

    // Addition Assignment Operator:
    cout<<"\nAddition Assignment Operator: "<<endl;
    cout<<"num1 += num2 is: num1 = "<<(num1 += num2)<<endl; // num1 = num1 + num2

    // Subtraction Assignment Operator:
    cout<<"\nSubtraction Assignment Operator: "<<endl;
    cout<<"num1 -= num2 is: num1 = "<<(num1 -= num2)<<endl; // num1 = num1 - num2

    // Multiplication Assignment Operator:
    cout<<"\nMultiplication Assignment Operator: "<<endl;
    cout<<"num1 *= num2 is: num1 = "<<(num1 *= num2)<<endl; // num1 = num1 * num2

    // Division Assignment Operator:
    cout<<"\nDivision Assignment Operator: "<<endl;
    cout<<"num1 /= num2 is: num1 = "<<(num1 /= num2)<<endl; // num1 = num1 / num2

    // Modulus Assignment Operator:
    cout<<"\nModulus Assignment Operator: "<<endl;
    cout<<"num1 %= num2 is: num1 = "<<(num1 %= num2)<<endl; // num1 = num1 % num2

    // // Increment Assignment Operator:
    // cout<<"\nIncrement Assignment Operator: "<<endl;
    // cout<<"num1++ is: num1 = "<<(num1++)<<endl;  // num1 = num1 + 1

    // // Decrement Assignment Operator:
    // cout<<"\nDecrement Assignment Operator: "<<endl;
    // cout<<"num1-- is: num1 = "<<(num1--)<<endl;  // num1 = num1 - 1

    cout<<"\nnum1 is: "<<num1<<endl;
    cout<<"num2 is: "<<num2<<endl;
    return 0;
}