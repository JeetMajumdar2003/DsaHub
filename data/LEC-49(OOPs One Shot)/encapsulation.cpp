#include <iostream>
using namespace std;

// Encapsulation is the process of binding together the data and functions that manipulates them.
class Encapsulation {
    private:
        int x;
    // Public functions to access the private data
    public:
        void set(int a) {
            x = a;
        }
        int get() {
            return x;
        }
};

int main() {
    // Encapsulation obj1;
    // cout<<obj1.x<<endl; // Error: 'int Encapsulation::x' is private

    // Create an object:
    Encapsulation obj;
    obj.set(5);
    cout << obj.get() << endl;
    return 0;
}

/**
// Encapsulation is also known as data hiding.
// The encapsulated data can only be accessed by the functions present inside the class.
// To access the private data, we need to create public functions (get and set) inside the class.
// The get function returns the value of the variable and the set function sets the value of the variable.
// The private data cannot be accessed directly outside the class.
*/