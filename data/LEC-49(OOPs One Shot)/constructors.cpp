#include <iostream>
using namespace std;

// Create a class:
class Rectangle{
    public:
        int length;
        int breadth;
        
        
        // Constructor: a special method that is called when an object is created

        // (1) Default constructor: no parameters
        Rectangle(){
            length = 0;
            breadth = 0;
        }

        // (2) Parameterized constructor: with parameters
        Rectangle(int l, int b){
            length = l;
            breadth = b;
        }

        // (3) Copy constructor: copy the values of one object to another object
        Rectangle(Rectangle &r){
            length = r.length;
            breadth = r.breadth;
        }

        // Destructor: a special method that is called when an object is destroyed, no parameters
        ~Rectangle(){
            cout<<"Destructor is Called"<<"\n";
        }
     
};

int main(){
    // Default constructor
    Rectangle r1;
    cout << r1.length << " " << r1.breadth << endl; // 0 0

    // Parameterized constructor
    Rectangle r2(10, 5);
    cout << r2.length << " " << r2.breadth << endl; // 10 5

    // Copy constructor
    Rectangle r3(r2);  // or Rectangle r3 = r2;
    cout << r3.length << " " << r3.breadth << endl; // 10 5

    // in the above object declaration, which is done using stack allocation, its destructor will be called automatically when the object goes out of scope.

    // but in the below object declaration, which is done using heap allocation, its destructor will not be called automatically when the object goes out of scope. so we have to call it manually.
    // Destructors
    Rectangle *r4 = new Rectangle();
    cout<<r4->length<<" "<<r4->breadth<<endl;
    delete r4;

    return 0;
}
