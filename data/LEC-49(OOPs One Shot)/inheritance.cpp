#include <iostream>
using namespace std;

// Modes of Access Specifiers: public, private, protected
// Public: members are accessible from outside the class
// Private: members cannot be accessed (or viewed) from outside the class
// Protected: members cannot be accessed from outside the class, however, they can be accessed in inherited classes like parent and child classes
class Parent {
    // Access specifier:
    public:
        int x;
    
    protected:
        int y;

    private:
        int z;
};

// Modes of Inheritance: public, private, protected
// Public: public members of the base class become public members of the derived class
// Private: public and protected members of the base class become private members of the derived class
// Protected: public members of the base class become protected members of the derived class
class Child1 : public Parent {
    // x is public
    // y is protected
    // z is not accessible from Child1
};

class Child2 : private Parent {
    // x is private
    // y is private
    // z is not accessible from Child2
};

class Child3 : protected Parent {
    // x is protected
    // y is protected
    // z is not accessible from Child2
};

int main() {
    // Public Inheritance
    Parent p;
    p.x = 10; // OK
    // p.y = 5; // Error: 'int Parent::y' is protected
    // p.z = 5; // Error: 'int Parent::z' is private

    return 0;
}
/*
 * Inheritance: Inheritance is the process of creating a new class from an existing class.
 * The new class is called the derived (or child) class and the existing class is called the base (or parent) class.
 * Child class inherits all the features of the parent class and it can have additional features of its own.
*/