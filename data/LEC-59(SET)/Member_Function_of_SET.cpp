#include<iostream>
#include<set>
using namespace std;

// class Member_Function_of_SET
// {
// public:
//     void insert();
//     void erase();
//     void find();
//     void clear();
//     void size();
//     void empty();
//     void begin();
//     void end();
//     void rbegin();
//     void rend();
//     void count();
//     void swap();
//     void equal_range();
//     void lower_bound();
//     void upper_bound();
// };

int main()
{
    set<int> s;
    for(int i=0;i<=100;i = i+10)
    {
        s.insert(i);
    }
    cout<<"Elements of set are: ";
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    // Member Function of SET:
    cout<<"Size of set is: "<<s.size()<<endl; // 11
    cout<<"Is set empty: "<<s.empty()<<endl;    // 0
    cout<<"First element of set is: "<<*s.begin()<<endl;    // 0
    cout<<"Last end position of set is: "<<*s.end()<<endl;  // garbage value
    cout<<"Last element of set is: "<<*--s.end()<<endl;  // 100
    cout<<"Reverse begin element of set is: "<<*s.rbegin()<<endl; // 100
    cout<<"Reverse end position of set is: "<<*s.rend()<<endl; // 0
    cout<<"Reverse end element of set is: "<<*--s.rend()<<endl; // 0
    cout<<"Element 10 is present in set or not: "<<s.count(10)<<endl; // 1
    // find() function is used to find the element in the set.
    if(s.find(10) != s.end()){
        cout<<"Element 10 is present in set."<<endl;
    }
    else{
        cout<<"Element 10 is not present in set."<<endl;
    }
    cout<<"Lower bound of 9 is: "<<*s.lower_bound(10)<<endl; // 10
    cout<<"Upper bound of 9 is: "<<*s.upper_bound(10)<<endl; // 20
}
