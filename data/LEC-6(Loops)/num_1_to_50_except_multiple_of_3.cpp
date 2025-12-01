#include <iostream>
using namespace std;

int main()
{
    // Print numbers from 1 to 50 except multiple of 3:
    int i = 1;
    while(i<=50){
        if(i%3==0){
            i++;
            continue;
        }
        cout<<i<<endl;
        i++;
    }
    return 0;
}