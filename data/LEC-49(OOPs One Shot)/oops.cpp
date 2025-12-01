#include <iostream>
using namespace std;

// // Create a class:
// class class_name {
//     // Properties
//     // Methods
// };

// create a class called Fruits:
class Fruits {
    // Access specifier
    public:
        string name;
        int price;
};

int main() {
    // Create an object of Fruits
    // Method 1: declare an object
    Fruits apple;   // object   // stack allocation
    apple.name = "Apple";
    apple.price = 100;
    cout << apple.name << " - " << apple.price << endl;

    // Method 2: new keyword
    Fruits *banana = new Fruits();      // pointer to object   // heap allocation
    banana->name = "Banana";
    banana->price = 50;
    cout << banana->name << " - " << banana->price << endl;
    return 0;
}


/**
 * In C++, the way you access members of an object depends on how the object is created.
 *
 * Stack Allocation:
 * -----------------
 * When you declare an object like this:
 * 
 *     Object obj;
 * 
 * You can access its members using the dot (.) operator:
 * 
 *     obj.method();
 *
 * Heap Allocation:
 * ----------------
 * When you create an object using the `new` keyword:
 * 
 *     Object* obj = new Object();
 * 
 * You need to use the arrow (->) operator to access its members:
 * 
 *     obj->method();
 *
 * The reason for this difference is that `new` returns a pointer to the object, 
 * and the arrow operator (->) is used to access members of an object through a pointer.
 */

/**
 * Great question! Here's a concise comparison between stack and heap allocation in C++:

Stack Allocation:
- Memory Management: Managed automatically by the compiler.
- Lifetime: Limited to the scope in which the variable is declared.
- Speed: Faster allocation and deallocation.
- Size: Typically smaller, as stack size is limited.
- Syntax: Direct declaration.
    ```cpp
    Object obj;
    obj.method();
    ```

Heap Allocation:
- Memory Management: Managed manually by the programmer using `new` and `delete`.
- Lifetime: Exists until explicitly deallocated.
- Speed: Slower allocation and deallocation.
- Size: Typically larger, as heap size is more flexible.
- Syntax: Uses pointers.
    ```cpp
    Object* obj = new Object();
    obj->method();
    delete obj;
    ```

Key Differences:
- Scope and Lifetime: Stack variables are automatically destroyed when the scope ends, while heap variables persist until explicitly deleted.
- Performance: Stack allocation is generally faster and more efficient, but limited in size. Heap allocation is more flexible but requires careful management to avoid memory leaks.

Does this help clarify the differences? If you have more questions or need further details, feel free to ask!
 */