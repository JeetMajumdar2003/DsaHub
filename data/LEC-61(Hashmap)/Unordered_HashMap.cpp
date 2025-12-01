#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Unordered map (roll no. -> name)
    unordered_map<int, string> record;

    // Inserting values
    record[4] = "Jeet";
    record[2] = "Urvi";
    record.insert({1, "Hitesh"});
    record.insert(make_pair(3, "Sanket"));
    record[4] = "Jeet Majumdar ";  // Duplicate keys are not allowed but value will be updated

    // Printing the record
    for(auto rec: record) {
        cout << rec.first << " " << rec.second << endl;
    }
        
    cout <<  "************************************" << endl;


    return 0;
}