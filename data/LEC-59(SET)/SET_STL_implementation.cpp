#include<iostream>
#include<set>
using namespace std;

// print the set
void print(set<int> s)
{
    for (auto x : s)
        cout << x << " ";
    cout << endl;
}

int main()
{
    set<int> s;  // set in ascending order, by default
    // set<int, greater<int>> s; // set in descending order

    // Inserting elements: Time complexity is O(logn)
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(15);
    cout<<s.size()<<endl;   // 4

    s.insert(5);
    s.insert(10);
    s.insert(20);
    s.insert(15);
    s.insert(30);
    s.insert(25);
    cout<<s.size()<<endl;   // 4 because set does not allow duplicate elements

    // Traversing the set: using iterator: Time complexity is O(n)
    /**
     * set<int>::iterator itr; // itr is a iterator which points to the current element
     * or we can use auto keyword to automatically detect the type of the iterator
     * for(itr = s.begin(); itr != s.end(); itr++)
     *     cout<<*itr<<" ";
     * cout<<endl;
    */
    cout << "The set elements are: ";
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " "; // itr is a iterator which points to the current element, *itr gives the value of the current element
    cout << endl;
    // using for each loop
    // cout << "The set elements are: ";
    // for (auto x : s)
    //     cout << x << " ";
    // cout << endl;

    // Erasing elements: Time complexity is O(logn)
    // Deleting a particular element: s.erase(element)-> O(logn)
    // s.erase(10);
    print(s);

    // Deleting all items from a particular position: s.erase(position)-> O(1)
    set<int>::iterator itr = s.begin();
    advance(itr, 2); // itr points to the 3rd element
    // s.erase(itr);
    print(s);

    // Deleting all elements from a particular range: s.erase(starting_position, ending_position)-> O(n)
    auto itr1 = s.begin();
    advance(itr1, 1);
    auto itr2 = s.begin();
    advance(itr2, 3);
    s.erase(itr1, itr2);
    print(s);

    return 0;
}