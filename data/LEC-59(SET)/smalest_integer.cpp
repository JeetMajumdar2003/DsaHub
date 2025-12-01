#include <iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
    vector<int> v(5);
    for(int i = 0; i < 5; i++) {
        cin>>v[i];
    }
    set<int> s(v.begin(), v.end());

    auto itr = s.begin();
    advance(itr, 1);
    cout <<"The second smallest element is: "<< *itr << "\n";

    return 0;
}