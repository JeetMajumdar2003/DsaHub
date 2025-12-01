#include<iostream>
using namespace std;

int sum(int a, int b=20, int c=30) // default value of b and c is 20 and 30 respectively
{
    int result;
    result = a + b + c;
    return (result);
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int result;

    // calling a function to add the values
    result = sum(a);
    cout << "Total value is :" << result << endl; // Total value is :51

    // calling a function again as follows
    result = sum(a, b);
    cout << "Total value is :" << result << endl; // Total value is :33

    // calling a function again as follows
    result = sum(a, b, c);
    cout << "Total value is :" << result << endl; // Total value is :6

    // calling a function again as follows
    // result = sum(); // gives error as no value is passed, so it will take default value of b and c as 20 and 30 respectively and a is not given any value.
    // cout << "Total value is :" << result << endl;
    return 0;
}