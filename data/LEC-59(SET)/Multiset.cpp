#include <iostream>
#include <set>
using namespace std;

int main() {
    // multiset<int> ms;
    multiset<int, greater<int>> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(2);
    ms.insert(3);

    for (auto i : ms) {
        cout << i << " ";
    }
    return 0;
}