#include <iostream>
using namespace std;

class GFG {
public:
    void call_Function() {
        print();
    }
    virtual void print() { // Using "virtual" for dynamic binding
        cout << "Printing the Base class Content" << endl;
    }
};

class GFG2 : public GFG {
public:
    void print() override { // Overriding the virtual function
        cout << "Printing the Derived class Content" << endl;
    }
};

int main() {
    GFG geeksforgeeks;
    geeksforgeeks.call_Function(); // Calls GFG::print()

    GFG2 geeksforgeeks2;
    geeksforgeeks2.call_Function(); // Calls GFG2::print() due to dynamic binding -> Runtime Decision

    return 0;
}

/** ### Dynamic Binding in OOP
 *
 * Dynamic binding, also known as late binding, is a concept in Object-Oriented Programming (OOP) where the method to be executed in response to a function call is determined at runtime. This is in contrast to static binding, where the method is determined at compile time.
 *
 * ### Key Points
 * - **Runtime Decision**: The method to be executed is decided at runtime, allowing for more flexible and dynamic behavior.
 * - **Virtual Functions**: In C++, dynamic binding is achieved using virtual functions. A virtual function is a function in a base class that can be overridden in derived classes.
 *
 * ### Example Without Dynamic Binding
 * Here's an example where dynamic binding is not used:
 *
 * ```cpp
 * #include <iostream>
 * using namespace std;
 *
 * class GFG {
 * public:
 *     void call_Function() {
 *         print();
 *     }
 *     void print() {
 *         cout << "Printing the Base class Content" << endl;
 *     }
 * };
 *
 * class GFG2 : public GFG {
 * public:
 *     void print() {
 *         cout << "Printing the Derived class Content" << endl;
 *     }
 * };
 *
 * int main() {
 *     GFG geeksforgeeks;
 *     geeksforgeeks.call_Function(); // Calls GFG::print()
 *
 *     GFG2 geeksforgeeks2;
 *     geeksforgeeks2.call_Function(); // Also calls GFG::print() due to static binding
 *
 *     return 0;
 * }
 * ```
 *
 * **Output:**
 * ```
 * Printing the Base class Content
 * Printing the Base class Content
 * ```
 *
 * In this example, the `print()` function of the base class is called even when using the derived class object. This is because the binding is static.
 *
 * ### Example With Dynamic Binding
 * Now, let's use virtual functions to achieve dynamic binding:
 *
 * ```cpp
 * #include <iostream>
 * using namespace std;
 *
 * class GFG {
 * public:
 *     void call_Function() {
 *         print();
 *     }
 *     virtual void print() { // Using "virtual" for dynamic binding
 *         cout << "Printing the Base class Content" << endl;
 *     }
 * };
 *
 * class GFG2 : public GFG {
 * public:
 *     void print() override { // Overriding the virtual function
 *         cout << "Printing the Derived class Content" << endl;
 *     }
 * };
 *
 * int main() {
 *     GFG geeksforgeeks;
 *     geeksforgeeks.call_Function(); // Calls GFG::print()
 *
 *     GFG2 geeksforgeeks2;
 *     geeksforgeeks2.call_Function(); // Calls GFG2::print() due to dynamic binding
 *
 *     return 0;
 * }
 * ```
 *
 * **Output:**
 * ```
 * Printing the Base class Content
 * Printing the Derived class Content
 * ```
 *
 * ### Explanation
 * - **Virtual Function**: The `print()` function in the base class `GFG` is declared as `virtual`.
 * - **Override**: The `print()` function in the derived class `GFG2` overrides the base class's virtual function.
 * - **Dynamic Binding**: When `call_Function()` is called on a `GFG2` object, the overridden `print()` function in `GFG2` is executed, demonstrating dynamic binding.
 *
 * ### Benefits of Dynamic Binding
 * - **Flexibility**: Allows for more flexible and reusable code.
 * - **Polymorphism**: Supports polymorphism, enabling objects to be treated as instances of their base class while still invoking derived class methods.
 *
 * Dynamic binding is a powerful feature in OOP that enhances the flexibility and maintainability of code by allowing method calls to be resolved at runtime.
 *
 * Does this help clarify dynamic binding? If you have more questions or need further details, feel free to ask!
 *
 * Source: Conversation with Copilot, 8/1/2024
 * (1) Dynamic Binding in C++ - GeeksforGeeks. https://www.geeksforgeeks.org/dynamic-binding-in-cpp/.
 * (2) Static vs Dynamic Binding in Java - GeeksforGeeks. https://www.geeksforgeeks.org/static-vs-dynamic-binding-in-java/.
 * (3) Introduction of Object Oriented Programming - GeeksforGeeks. https://www.geeksforgeeks.org/introduction-of-object-oriented-programming/.
 * (4) Dynamic Binding: Class-Appropriate behavior - ODU. https://www.cs.odu.edu/~zeil/cs330/latest/Public/dynamicBinding/index.html.
 * (5) Dynamic Binding: Class-Appropriate behavior. https://www.cs.odu.edu/~tkennedy/cs330/s20/Public/dynamicBinding/index.html.
 */