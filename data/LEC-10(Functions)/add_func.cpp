#include <iostream>
using namespace std;

// Add Function: add two numbers
int add(int x, int y){
    return x + y;
}

// Add Function: add three numbers
int add(int x, int y, int z){
    return x + y + z;
}

// Add Function: add two floating numbers
float add(float num1, float num2){
    return num1 + num2;
}

int main(){
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Sum = " << add(a, b) << endl;

    int c, d, e;
    cout << "Enter three numbers: ";
    cin >> c >> d >> e;
    cout << "Sum = " << add(c, d, e) << endl;

    float num1, num2;
    cout << "Enter two float numbers: ";
    cin >> num1 >> num2;
    cout << "Sum = " << add(num1, num2) << endl;
    return 0;
}