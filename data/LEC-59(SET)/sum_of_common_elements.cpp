#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of elements in the first set: ";
    cin >> n;
    cout << "Enter the number of elements in the second set: ";
    cin >> m;
    vector<int> v1(n), v2(m);
    cout << "Enter the elements of the first set: ";
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    cout << "Enter the elements of the second set: ";
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    set<int> s1(v1.begin(), v1.end()); // insert elements of v1 into s1
    set<int> s2(v2.begin(), v2.end()); // insert elements of v2 into s2
    int sum = 0;
    for (auto i : s1) {
        if (s2.find(i) != s2.end()) {
            sum += i;
        }
    }
    cout << "The sum of common elements of the two sets is: " << sum << endl;

    return 0;
}