#include <iostream>
using namespace std;

int main()
{
    // Break Keyword:
    // The break keyword is used to break out of a loop.(Nearest Loop)
    // It is used inside the body of the loop.
    // When the break keyword is encountered inside a loop, the loop is immediately terminated and the program control resumes at the next statement following the loop.
    // It can be used to terminate a for loop, a while loop, or a do...while loop.

    // Example:
    while(true){
        int num;
        cout<<"Enter a number: ";
        cin>>num;
        if(num<0){
            cout<<"You entered a negative number."<<endl;
            break;
        }
        cout<<"You entered: "<<num<<endl;
    }
    return 0;
}