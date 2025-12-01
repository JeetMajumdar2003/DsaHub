#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;
    int n,p,q;
    cin>>n>>p>>q;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            int correct = i;
            int incorrect = j;
            int unattempted = n - correct - incorrect;
            if(unattempted >= 0){
                int marks = correct*p + incorrect*q;
                s.insert(marks);
            }
            else{
                break;
            }
        }
    }

    cout << s.size() << "\n";
    return 0;
}