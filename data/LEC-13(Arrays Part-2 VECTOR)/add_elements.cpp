#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30};
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Insert 40 to the last position
    v.push_back(40);
    // Print the vector
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Insert 50 in between 20 and 30
    v.insert(v.begin()+2, 50);
    // Print the vector
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Insert 60 at the beginning
    v.insert(v.begin(), 60);
    // Print the vector
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Insert multiple elements at the beginning
    v.insert(v.begin(), {1, 2, 3});
    // Print the vector
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Insert multiple elements at the end
    v.insert(v.end(), {70, 80, 90, 100});
    // Print the vector
    for (int x : v)
        cout << x << " ";
    return 0;
}