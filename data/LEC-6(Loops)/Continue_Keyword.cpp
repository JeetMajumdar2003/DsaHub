#include <iostream>
using namespace std;

int main()
{
    // Continue Keyword:
    /*
    The continue keyword is used to skip the current iteration of the loop.
    It is used with for, while and do-while loops.
    It is used to skip the current iteration of the loop and the control of the program goes to the next iteration.*/

    // Example:
    for(int i=1; i<=10; i++)
    {
        if(i==5)
            continue;
        cout<<i<<endl;
    }
    return 0;
}