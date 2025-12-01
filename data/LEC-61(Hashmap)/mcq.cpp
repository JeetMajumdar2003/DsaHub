#include <iostream>
#include<map>
using namespace std;

int main() {
    // Multimap
    multimap<int, int> m;

    m.insert({1, 40});
    m.insert({2, 30});
    m.insert({3, 60});
    m.insert({4, 20});
    m.insert({4, 50});
    m.insert({4, 70});

    auto a = m.equal_range(4);  // Returns a pair of iterators, which shows the range of elements with key 4(both are inclusive)

    for(auto it = a.first; it != a.second; it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}