#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 20;
    char ch = 'A';

    // Size of operator
    cout << "Size of a = " << sizeof(a) << endl;
    cout << "Size of ch = " << sizeof(ch) << endl;

    // Ternary operator
    int x = 10, y = 20;
    x==y ? cout << "Equal" : cout << "Not Equal"<<endl;

    // Comma operator
    int i = 1, j = 2, k = 3;
    int m = (i, j, k); // m = k = 3 (last value)
    cout << m << endl;
    
    // Dot operator (structure)
    struct student
    {
        int roll;
        char name[20];
    };
    student s1 = {1, "Jeet Majumdar"};
    cout << s1.roll << endl; // s1.roll = 1
    cout << s1.name << endl; // s1.name = Jeet Majumdar

    // Arrow operator (pointer to structure)
    student *s2 = &s1;
    cout << s2->roll << endl; // s2->roll = 1
    cout << s2->name << endl; // s2->name = Jeet Majumdar

    // Scope resolution operator
    int x1 = 10;
    {
        int x1 = 20;
        cout << x1 << endl;
    }
    cout << x1 << endl; // x1 = 10

    // Casting operator
    float x2 = 3.14;
    int y2 = int(x2); // int(x2) or (int)x2 (both are same)
    cout << x2 << endl; // x2 = 3.14
    cout << y2 << endl; // y2 = 3

    // Reference operator
    int x3 = 10;
    int &y3 = x3; // y3 is a reference to x3 (both are same) that means if we change the value of y3 then x3 will also change and vise versa
    cout <<"x3: "<< x3 << endl; // x3 = 10
    cout <<"y3: "<< y3 << endl; // y3 = 10
    // changing the value of y3
    x3 = 20; // or y3 = 20
    cout << "Now new x3: " << x3 << endl; // Output: x3: 20
    cout << "Now new y3: " << y3 << endl; // Output: y3: 20

    // Pointer operator
    int x4 = 20;
    int *y4 = &x4;
    cout <<"x4: "<< x4 << endl; // x4 = 20
    cout <<"Address of x4 = y4: "<< y4 << endl; // y4 = 0x61fda8

    // Address operator
    int x5 = 10;
    cout <<"Address of x5: "<< &x5 << endl; // &x5 = 0x61fda4
    
    // Indirection operator(Value at)
    int x6 = 10;
    int *y6 = &x6;
    cout <<"x6: "<< x6 << endl; // x6 = 10
    cout <<"Value at y6: "<< *y6 << endl; // *y6 = 10

    return 0;
}