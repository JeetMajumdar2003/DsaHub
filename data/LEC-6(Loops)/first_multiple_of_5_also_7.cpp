#include <iostream>
#include <ostream>
using namespace std;

int main()
{
    // Find the first multiple of 5 and 7:
    // M-1
    int mul = 1;
    while(true){
        if(mul%5==0 && mul%7==0){
            cout<<mul<<endl;
            break;
        }
        mul++;
    }

    // M-2
    int i = 5;
    while(true){
        if(i%7==0){
            cout<<i<<endl;
            break;
        }
        i+=5;
    }

    // M-3
    int j = 5;
    while(true){
        if(j%5==0){
            if(j%7==0){
                cout<<j<<endl;
                break;
            }
        }
        j++;
    }

    // M-4
    // int k = 5;
    // while(true){
    //     (k%5==0 && k%7==0)?cout<<k<<endl:k++;
    // }

    return 0;
}