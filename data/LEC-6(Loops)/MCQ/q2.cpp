#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    for (int i = 1; i < 5; i++){
    } 
    cout<<i<<endl; // 0

    // give me the explanation:
    // The scope of i(initialized as int i = 1) in for loop is limited to the for loop only.  
    // So, the value of i outside the for loop is 0.

    // but if we only update the value of i(i=1) inside the for loop then the value of i is also changed.
    // like:
    for (i = 1; i < 5; i++){
    }
    cout<<i<<endl;
    return 0;
}