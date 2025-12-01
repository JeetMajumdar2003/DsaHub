#include <iostream>
using namespace std;

// Runtime polymorphism: same function name, same parameters, different classes

// class Animal {
// public:
//     virtual void makeSound() {
//         cout << "The animal makes a sound" << endl;
//     }
// };
// class Dog : public Animal {
// public:
//     void makeSound() {
//         cout << "The dog barks" << endl;
//     }
// };
// class Cat : public Animal {
// public:
//     void makeSound() {
//         cout << "The cat meows" << endl;
//     }
// };
// int main() {
//     Animal* animal;
//     Dog dog;
//     Cat cat;
//     animal = &dog;
//     animal->makeSound(); // Output: The dog barks
//     animal = &cat;
//     animal->makeSound(); // Output: The cat meows
//     return 0;
// }


class Parent{
public:
    virtual void print(){   // virtual keyword is used to make function overridding
        cout << "Parent Class" << endl;
    }
    void show(){
        cout << "Parent Class" << endl;
    }
};

class Child : public Parent{
public:
    void print(){
        cout << "Child Class" << endl;
    }
    virtual void show(){
        cout << "Child Class" << endl;
    }
};

int main(){
    Parent *p;  // Base class pointer
    Child c;    // Derived class object

    p = &c;
    p->print(); // Output: Child Class, because print() is virtual function in Parent class, it is overriden in Child class
    p->show();  // Output: Parent Class
    c.print();  // Output: Child Class
    c.show();   // Output: Child Class
    return 0;
}