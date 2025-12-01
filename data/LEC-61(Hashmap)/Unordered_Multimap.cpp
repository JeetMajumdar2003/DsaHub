#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
    // Unordered Multimap
    unordered_multimap<string, int> fruitCount;

    // Inserting elements
    fruitCount.insert(pair<string, int>("Apple", 10));
    fruitCount.insert({"Banana", 20});
    fruitCount.insert({"Apple", 30});
    fruitCount.insert(make_pair("Mango", 40));
    fruitCount.insert(make_pair("Mango", 50));

    // Printing elements
    for(auto pair : fruitCount) {
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}