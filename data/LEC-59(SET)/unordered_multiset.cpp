#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_multiset<int> ms;
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