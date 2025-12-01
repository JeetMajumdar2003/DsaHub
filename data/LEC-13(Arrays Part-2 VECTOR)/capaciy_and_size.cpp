#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v; // size = 0, capacity = 0
    cout <<"Size; "<<v.size() << endl; // 0
    cout <<"Capacity: "<<v.capacity() << endl; // 0

    // Insert elements
    v.push_back(1); // size = 1, capacity = 1
    cout <<"Size: "<<v.size() << endl; // 1
    cout <<"Capacity: "<<v.capacity() << endl; // 1

    v.push_back(2); // size = 2, capacity = 2
    cout <<"Size: "<<v.size() << endl; // 2
    cout <<"Capacity: "<<v.capacity() << endl; // 2

    v.push_back(3); // size = 3, capacity = 4
    cout <<"Size: "<<v.size() << endl; // 3
    cout <<"Capacity: "<<v.capacity() << endl; // 4

    v.push_back(4); // size = 4, capacity = 4
    cout <<"Size: "<<v.size() << endl; // 4
    cout <<"Capacity: "<<v.capacity() << endl; // 4
    
    //Resize
    v.resize(5); // size = 5, capacity = 8
    cout<<"Size: " << v.size() << endl; // 5
    cout<<"Capacity: " << v.capacity() << endl; // 8

    v.resize(15); // size = 15
    cout<<"Size: " << v.size() << endl; // 15
    cout<<"Capacity: " << v.capacity() << endl; // Compilers may give different values for capacity
}