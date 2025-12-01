#include <iostream>
using namespace std;

int main()
{
    // Insert Element in an Array using for loop
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter the element "<<i+1<<": ";
        cin >> arr[i];
    }
    // Print the array
    cout << "The array elements are: ";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Using for each Loop:
    char vowels[5];
    for (char& i : vowels){ // &(ampersand) is used to access the address of the variable
        cout << "Enter the vowel: ";
        cin >> i;
    }
    cout << "The vowels are: ";
    for (char i : vowels)
        cout << i << " ";
    return 0;
}