#include <iostream>
using namespace std;

void printNum(int n){
    // base case
    if(n<1) return;
    // assumption: printNum(n-1) corectly print first n-1 numbers 
    printNum(n-1);
    // self work
    cout<<n<<" ";
}

int main()
{
    printNum(20);
    return 0;
}