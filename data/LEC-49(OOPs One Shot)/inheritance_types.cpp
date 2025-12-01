#include <iostream>
using namespace std;

// Types of Inheritance:

// 1. Single Inheritance1: A -> B, A is base class, B is derived class:
class Parent {
    public:
        Parent() {
            cout << "Parent Constructor" << endl;
        }
};
class Child : public Parent {
    public:
        Child() {
            cout << "Child Constructor" << endl;
        }
};

// 2. Multilevel Inheritance: A -> B -> C, A is base class, B is derived class, C is derived class:
class GrandParent {
    public:
        GrandParent() {
            cout << "GrandParent Constructor" << endl;
        }
};
class Parent1 : public GrandParent {
    public:
        Parent1() {
            cout << "Parent1 Constructor" << endl;
        }
};
class Child1 : public Parent1 {
    public:
        Child1() {
            cout << "Child1 Constructor" << endl;
        }
};

// 3. Multiple Inheritance: A -> C, B -> C, A and B are base class, C is derived class:
class Parent2 {
    public:
        Parent2() {
            cout << "Parent2 Constructor" << endl;
        }
};
class Parent3 {
    public:
        Parent3() {
            cout << "Parent3 Constructor" << endl;
        }
};
class Child2 : public Parent2, public Parent3 {
    public:
        Child2() {
            cout << "Child2 Constructor" << endl;
        }
};

// 4. Hierarchical Inheritance: A -> B, A -> C, A is base class, B and C are derived class:
class Parent4 {
    public:
        Parent4() {
            cout << "Parent4 Constructor" << endl;
        }
};
class Child3 : public Parent4 {
    public:
        Child3() {
            cout << "Child3 Constructor" << endl;
        }
};
class Child4 : public Parent4 {
    public:
        Child4() {
            cout << "Child4 Constructor" << endl;
        }
};

// 5. Hybrid Inheritance: A -> B, A -> C, B -> D, C -> D, A is base class, B and C are derived class, D is derived class:
class Parent5 {
    public:
        Parent5() {
            cout << "Parent5 Constructor" << endl;
        }
};
// Hierarchical Inheritance:
class Child5 : public Parent5 {
    public:
        Child5() {
            cout << "Child5 Constructor" << endl;
        }
};
class Child6 : public Parent5 {
    public:
        Child6() {
            cout << "Child6 Constructor" << endl;
        }
};
// Multiple Inheritance +  
class Child7 : public Child5, public Child6 {
    public:
        Child7() {
            cout << "Child7 Constructor" << endl;
        }
};



int main() {
    // Single Inheritance:
    cout << "<-----------Single Inheritance:-------------->" << endl;
    Child c1;
    cout << endl;

    // Multilevel Inheritance:
    cout << "<-----------Multilevel Inheritance:-------------->" << endl;
    Child1 c2;
    cout << endl;

    // Multiple Inheritance:
    cout << "<-----------Multiple Inheritance:-------------->" << endl;
    Child2 c3;
    cout << endl;

    // Hierarchical Inheritance:
    cout << "<-----------Hierarchical Inheritance:-------------->" << endl;
    Child3 c4;
    Child4 c5;
    cout << endl;

    // Hybrid Inheritance:
    cout << "<-----------Hybrid Inheritance:-------------->" << endl;
    Child7 c6;
    cout << endl;

    return 0;
}
