#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// Hashing Class
class Hashing {
    vector<list<int>> hashTable;
    int bucketSize;

    public:
    Hashing(int size) {
        bucketSize = size;
        hashTable.resize(bucketSize);
    }

    // Hash Function
    int hashFunction(int key) {
        return key % bucketSize;    // Modulo Hashing or Division Hashing
    }

    // Insert Key -> O(1)
    void insertKey(int key) {
        int index = hashFunction(key);
        hashTable[index].push_back(key);
    }

    // Search Key -> O(1)
    list<int>::iterator searchKey(int key) {
        int index = hashFunction(key);
        return find(hashTable[index].begin(), hashTable[index].end(), key); // return iterator
    }

    // Search Key index -> O(n)
    int searchKeyIndex(int key) {
        int index = hashFunction(key);
        list<int>::iterator i;
        for(i = hashTable[index].begin(); i != hashTable[index].end(); i++) {
            if(*i == key) {
                break;
            }
        }
        if(i != hashTable[index].end()) {
            return index;   // return index
        } else {
            return -1;
        }
    }

    // Delete Key -> O(1)
    void deleteKey(int key) {
        int index = hashFunction(key);
        if(searchKey(key) != hashTable[index].end()){
            hashTable[index].erase(searchKey(key));
        }
        // list<int>::iterator i;
        // for(i = hashTable[index].begin(); i != hashTable[index].end(); i++) {
        //     if(*i == key) {
        //         break;
        //     }
        // }
        // if(i != hashTable[index].end()) {
        //     hashTable[index].erase(i);
        // }
    }

    // Print Hash Table
    void printHashTable() {
        for(int i = 0; i < bucketSize; i++) {
            cout << i;
            for(auto x : hashTable[i]) {
                cout << " --> " << x;
            }
            cout << endl;
        }
    }
};

int main() {
    // Create Hashing Object
    Hashing h(7);   // Bucket Size = 7 and hashFunction = key % 7

    // Insert Keys
    h.insertKey(10);
    h.insertKey(20);
    h.insertKey(15);
    h.insertKey(7);
    h.insertKey(9);
    h.insertKey(8);

    // Print Hash Table
    h.printHashTable();

    // Search Keys
    list<int>::iterator i;
    i = h.searchKey(15);
    cout << *i << endl;

    // Search Key Index
    int index = h.searchKeyIndex(15);
    cout << index << endl;

    // Delete Keys
    h.deleteKey(15);

    // Print Hash Table
    h.printHashTable();


    return 0;
}