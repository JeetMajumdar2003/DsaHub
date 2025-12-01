#include <iostream>
#include<map>
using namespace std;

int main() {
    // Multimap
    multimap<string, int> phoneBook;

    // Inserting elements
    phoneBook.insert(pair<string, int>("John", 1234));  // pair is used to make a pair
    phoneBook.insert({"John", 5678});
    phoneBook.insert({"Sam", 121314});
    phoneBook.insert(make_pair("Alex", 91011)); // make_pair() is used to make a pair
    // phoneBook["Alex"] = 12345; // Overwriting the value of Alex is not possible in multimap

    // Printing elements
    for(auto i = phoneBook.begin(); i != phoneBook.end(); i++) {
        cout << i->first << " " << i->second << endl;
    }


    return 0;
}