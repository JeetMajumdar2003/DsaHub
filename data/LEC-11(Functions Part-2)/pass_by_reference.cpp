#include<iostream>
using namespace std;

void swap(int& x, int& y) {  // x and y are references to a and b => x and y are aliases of a and b => int &x = a, int &y = b
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << " b = " << b << endl;
    swap(a, b); // call by reference address of a and b is passed
    cout << "After swap: a = " << a << " b = " << b << endl;

    // References
    int p = 5;
    int& q = p; // q is a reference to p (q is another name for p)
    cout << "p = " << p << " q = " << q << endl;
    q = 10; // changing q will change p
    cout << "p = " << p << " q = " << q << endl;
    // int& r = 10; // error: r must be a reference to a variable, r must be initialized to a variable

    // print address of p and q
    cout << "Address of p = " << &p << " Address of q = " << &q << endl;

    return 0;
}

    // (Q) What is int &a = b; mean?
/*
    Ans: The text "int &a = b" is a C++ statement that creates a reference variable 'a' which refers to an existing integer variable 'b'. This means that 'a' is an alias for 'b', and any changes made to 'a' will also affect the value of 'b'. A reference variable is a way of creating a new name for an existing variable, without creating a copy of its value. It can be useful for passing arguments to functions by reference, which allows the function to modify the original variable. 

To understand the syntax of the statement, let's look at its components:

- `int` is the data type of the variable 'b', which is an integer. The reference variable 'a' must have the same data type as the variable it refers to.
- `&` is the symbol that indicates that 'a' is a reference variable. It is placed before the name of the reference variable, and it means "address of". It tells the compiler that 'a' is not a normal variable, but a reference to another variable's memory location.
- `a` is the name of the reference variable. It can be any valid identifier, as long as it is not already used by another variable in the same scope.
- `=` is the assignment operator, which assigns the value of the right-hand side expression to the left-hand side variable. In this case, it assigns the reference of 'b' to 'a'.
- `b` is the name of the existing integer variable that 'a' refers to. It must be already declared and initialized before creating a reference to it.

Here is an example of how to use a reference variable in C++:

```cpp
#include <iostream>

int main() {
    int b = 10; // Declare and initialize an integer variable 'b'
    int &a = b; // Create a reference variable 'a' that refers to 'b'
    std::cout << "The value of b is: " << b << std::endl; // Print the value of 'b'
    std::cout << "The value of a is: " << a << std::endl; // Print the value of 'a'
    a = 20; // Modify the value of 'a'
    std::cout << "The value of b after changing a is: " << b << std::endl; // Print the value of 'b' again
    std::cout << "The value of a after changing a is: " << a << std::endl; // Print the value of 'a' again
    return 0;
}
```

The output of this program is:

```
The value of b is: 10
The value of a is: 10
The value of b after changing a is: 20
The value of a after changing a is: 20
```

You can see that changing the value of 'a' also changes the value of 'b', because they refer to the same memory location.

I hope this explanation helps you understand what "int &a = b" means in C++. If you want to learn more about reference variables in C++, you can check out this [tutorial] or this [documentation].
*/