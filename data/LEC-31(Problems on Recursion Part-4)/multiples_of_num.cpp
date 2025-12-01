#include <iostream>
using namespace std;

void printMultiple(int num, int k){
    // base case
    if(k<1) return;
    // assumption: printMultiple(num, k-1) corectly print first (k-1) multiples of num: 
    printMultiple(num, k-1);
    // self work
    cout<<num*k<<" ";
}

int main()
{
    printMultiple(2,10);
    return 0;
}