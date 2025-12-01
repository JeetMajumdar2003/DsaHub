#include <iostream>
using namespace std;

int main()
{
    bool exp1 = true;
    bool exp2 = false;

    cout<<"\n<---Logical AND(&&)--->"<<endl;
    // Logical AND(&&):
    cout<<"Logical AND of exp1 and exp1 is: "<<(exp1 && exp1)<<endl; // true
    cout<<"Logical AND of exp1 and exp2 is: "<<(exp1 && exp2)<<endl; // false
    cout<<"Logical AND of exp2 and exp1 is: "<<(exp2 && exp1)<<endl; // false
    cout<<"Logical AND of exp2 and exp2 is: "<<(exp2 && exp2)<<endl; // false

    cout<<"\n<---Logical OR(||)--->"<<endl;
    // Logical OR(||):
    cout<<"Logical OR of exp1 and exp1 is: "<<(exp1 || exp1)<<endl; // true
    cout<<"Logical OR of exp1 and exp2 is: "<<(exp1 || exp2)<<endl; // true
    cout<<"Logical OR of exp2 and exp1 is: "<<(exp2 || exp1)<<endl; // true
    cout<<"Logical OR of exp2 and exp2 is: "<<(exp2 || exp2)<<endl; // false

    cout<<"\n<---Logical NOT(!)--->"<<endl;
    // Logical NOT(!):
    cout<<"Logical NOT of exp1 is: "<<(!exp1)<<endl; // false
    cout<<"Logical NOT of exp2 is: "<<(!exp2)<<endl; // true
    return 0;
}