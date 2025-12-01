#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout<<endl;

    // Member functions of unordered_set

    // 1. begin() - Returns an iterator to the first element in the unordered_set.
    // 2. end() - Returns an iterator to the theoretical element that follows the last element in the unordered_set.
    // 3. size() - Returns the number of elements in the unordered_set.
    // 4. max_size() - Returns the maximum number of elements that the unordered_set can hold.
    // 5. empty() - Returns whether the unordered_set is empty.
    // 6. insert(const g) - Adds a new element 'g' to the unordered_set.
    // 7. erase(const g) - Removes the value 'g' from the unordered_set.
    // 8. clear() - Removes all the elements from the unordered_set.
    // 9. find(const g) - Returns an iterator to the element 'g' in the unordered_set if found, else returns the iterator to end.
    // 10. count(const g) - Returns the number of elements matching specific element 'g'.
    
    return 0;
}