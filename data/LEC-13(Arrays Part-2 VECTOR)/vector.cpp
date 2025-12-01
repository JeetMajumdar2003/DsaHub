#include <iostream>
#include <vector>
using namespace std;

int main(){
    // Vector is a dynamic array
    // Declaration of vector:
    vector<int> v;

    // Initialization of vector:
    vector<int> v1(5, 1); // 5 elements with value 1
    vector<int> v2{1, 2, 3, 4, 5};
    vector<int> v3 = {6, 7, 8, 9, 10};

    // Size of vector:
    cout<<"Size; " << v.size() << endl;
    cout<<"Size; " << v1.size() << endl;
    cout<<"Size; " << v2.size() << endl;
    cout<<"Size; " << v3.size() << endl;

    // Resize of vector:
    v.resize(10);// 10 elements with value 0
    cout<<"Resize; " << v.size() << endl;  // 10

    // Capacity of vector: It is the size of the underlying array of the vector and is always greater than or equal to the size of the vector.
    cout<<"Capacity: " << v.capacity() << endl;  // 10

    // Capacit >= size:
    v.resize(8);
    cout<<"Capacity: " << v.capacity() << endl; // gives random value (>=8) as capacity is not changed after resize to smaller size (8) from larger size (10).
    cout<<"Size; "<<v.size()<<endl;
    v.resize(15);
    cout<<"Resize; "<<v.size()<<endl;
    cout<<"Capacity: " << v.capacity() << endl; // gives random value (>=15)

    return 0;
}