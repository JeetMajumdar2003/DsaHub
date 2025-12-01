#include <iostream>
#include<map>
using namespace std;

int main() {
    // Declaring a map
    map<string, int> phonebook; // accending order
    // map<string, int, greater<string> > phonebook; // descending order


    // Inserting values
    phonebook["Jeet"] = 12345;
    phonebook["Urvi"] = 67890;
    phonebook["Sanket"] = 54321;
    phonebook["Hitesh"] = 98765;

    // Printing the phonebook
    for(auto ph: phonebook) {
        cout << ph.first << " " << ph.second << endl;
    }

    cout <<  "************************************" << endl;
    
    // Duplicate keys are not allowed
    // phonebook["Jeet"] = 54321;  // Duplicate keys are not allowed but value will be updated

    // insert function will not update the value if key is already present
    // phonebook.insert({"Jeet", 54321});
    // phonebook.insert(make_pair("Jeet", 54321));

    // for(auto ph: phonebook) {
    //     cout << ph.first << " " << ph.second << endl;
    // }

    // iterate over the map using iterator
    // map<string, int>::iterator itr;
    // for(itr = phonebook.begin(); itr != phonebook.end(); itr++) {
    //     cout << itr->first << " " << itr->second << endl;
    // }
    map<string, int>::reverse_iterator itr;
    for(itr = phonebook.rbegin(); itr != phonebook.rend(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }
    return 0;
}