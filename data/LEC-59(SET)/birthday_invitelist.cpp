#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> invitelist;
    int n;
    cout << "Enter the number of people you want to invite: ";
    cin >> n;

    cout << "Enter the name of the person: ";
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        invitelist.insert(name);
    }

    cout << "The people you have invited are: "<<endl;
    for (auto name : invitelist) {
        cout << name << endl;
    }
    return 0;
}