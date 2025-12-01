#include <iostream>
using namespace std;

int main()
{
    // Array declaration by initializing elements
    int arr3[] = {1, 2, 3, 4, 5};
    // Accessing elements of an array(Traversing an array using for loop)
    for(int idx = 0; idx < 5; idx++)
        cout << arr3[idx] << " ";
    cout << endl;

    // Array declaration by specifying size and initializing elements
    int arr4[6] = {10, 20, 30, 40, 50, 60};
    // Accessing elements of an array (Method 2)(Traversing an array using for-each loop)
    for(int ele: arr4)
        cout << ele << " ";
    cout << endl;

    // Array declaration by specifying size and initializing elements
    int arr5[6] = {100, 200, 300, 400};
    // Accessing elements of an array (Method 3)(Traversing an array using while loop)
    int idx = 0; // index   
    while(idx < 6){
        cout << arr5[idx] << " ";
        idx++;
    }
    cout << endl;

    // Array declaration by specifying size and initializing elements
    int arr6[6] = {0};
    // Accessing elements of an array (Method 4)(Traversing an array using do-while loop)
    int i = 0; // index
    do{
        cout << arr6[i] << " ";
        i++;
    }while(i < 6);
    return 0;
}