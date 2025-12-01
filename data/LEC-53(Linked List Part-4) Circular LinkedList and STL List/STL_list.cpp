#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l1 = {1,2,3,8,6};

    // Iterator: It is a pointer that points to an element of a list
    list<int>::iterator itr = l1.begin();
    // OR
    auto itr1 = l1.begin();
    cout<<*itr<<endl;
    cout<<*itr1<<endl;

    auto itr2 = l1.end(); // l1.end() iterator pointing to the memory location after the last element of the list
    cout<<*itr2<<endl; // This will give some garbage value

    auto itr3 = l1.rbegin(); // l1.rbegin() iterator pointing to the last element of the list
    cout<<*itr3<<endl;

    auto itr4 = l1.rend(); // l1.rend() iterator pointing to the memory location before the first element of the list
    cout<<*itr4<<endl; // This will give some garbage value

    advance(itr, 2); // This will move the iterator itr to 2 positions ahead
    cout<<*itr<<endl;



    // Traverse the list using range based for loop
    for(int &i : l1){
        cout<<i<<"->";
    }cout<<"NULL"<<endl;

    // Traverse the list using iterator
    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout<<*itr<<"->";
    }cout<<"NULL"<<endl;

    // Traverse the list using iterator
    for(auto itr = l1.rbegin(); itr != l1.rend(); itr++){
        cout<<*itr<<"->";
    }cout<<"NULL"<<endl;


    // Inserting elements in the list
    list<int> l2 = {1,2,3,4,5};
    auto itr5 = l2.begin();
    advance(itr5, 2);
    l2.insert(itr5, 8); // This will insert 8 at the 3rd position
    for(int &i : l2){
        cout<<i<<"->";
    }cout<<"NULL"<<endl;

    // Inserting elements in the list
    list<int> l3 = {1,2,3,4,5};
    auto itr6 = l3.begin();
    advance(itr6, 3);
    l3.insert(itr6, 3, 8); // This will insert 8, 8, 8 at the 4th position
    for(int &i : l3){
        cout<<i<<"->";
    }cout<<"NULL"<<endl;

    // Inserting elements in the list
    list<int> l4 = {1,2,3,4,5};
    auto itr7 = l4.begin();
    advance(itr7, 3);
    auto l = l4.begin();
    advance(l, 1);
    auto r = l4.begin();
    advance(r, 3);
    l4.insert(itr7, l, r); // This will insert 2, 3 at the 4th position
    for(int &i : l4){
        cout<<i<<"->";
    }cout<<"NULL"<<endl;

    // Inserting elements in the list
    list<int> l5 = {1,2,3,4,5};
    auto itr11 = l5.begin();
    advance(itr11, 3);
    list<int> l6 = {10, 20, 30};
    l5.insert(itr11, l6.begin(), l6.end()); // This will insert 10, 20, 30 at the 4th position

    // Removing elements from the list
    list<int> l66 = {1,2,3,4,5};
    auto itr8 = l66.begin();
    advance(itr8, 2);
    l66.erase(itr8); // This will erase the 3rd element
    for (int &i : l66){
        cout<<i<<"->";
    }cout<<"NULL"<<endl;

    // Removing elements from the list
    list<int> l7 = {1,2,3,4,5};
    auto itr9 = l7.begin();
    advance(itr9, 1);
    auto itr10 = l7.begin();
    advance(itr10, 4);
    l7.erase(itr9, itr10); // This will erase the 3rd and 4th element
    for (int &i : l7){
        cout<<i<<"->";
    }cout<<"NULL"<<endl;
}