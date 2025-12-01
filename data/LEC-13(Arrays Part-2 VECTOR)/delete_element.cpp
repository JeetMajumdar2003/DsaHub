#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50, 60};
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Delete last element
    v.pop_back();
    // Print the vector
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Delete the third element
    // v.erase(v.begin()+2);
    // OR
    v.erase(v.end()-3);
    // Print the vector
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Delete a range of elements: (1, 3) i.e. 20 and 40
    v.erase(v.begin()+1, v.begin()+3);
    // Print the vector
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Clear the vector
    v.clear();
    // Print the vector
    for (int x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}