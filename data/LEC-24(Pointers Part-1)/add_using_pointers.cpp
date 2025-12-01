#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cout<< "Enter the value of x: ";
    cin>>x;
    cout<< "Enter the value of y: ";
    cin>>y;

    int *ptrx, *ptry;
    ptrx = &x;
    ptry = &y;
    cout<<"Address of x = "<<ptrx<<endl;
    cout<<"Address of y = "<<ptry<<endl;

    int result;
    int *ptr_result = &result;

    *ptr_result = *ptrx + *ptry;

    cout<<"Result = "<<result<<endl;
    cout<<"Result = "<<*ptr_result<<endl;
    cout<<"Address of result = "<<ptr_result<<endl;
    return 0;
}

/*
 * *ptrx -> 10
 * *ptry -> 20
 * *ptrx + *ptry -> 30
 * *ptr_result -> 30; we store the value of *ptrx + *ptry in *ptr_result
 * result -> 30
*/