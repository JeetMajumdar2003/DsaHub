#include <bits/stdc++.h>
using namespace std;

// Selection Sort In String Function:
void selectionSortString(char fruit[][60], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        // finding the minimum element
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(fruit[min_idx], fruit[j]) > 0)
            {
                min_idx = j;
            }
        }

        // place the minimum element at the begining
        if (min_idx != i)
        {
            swap(fruit[i], fruit[min_idx]);
            // char temp[60];
            // strcpy();
        }
    }
    return;
}

int main()
{
    char fruit[][60] = {"papaya", "lime", "watermelon", "apple", "mango", "kiwi"};

    int n = sizeof(fruit) / sizeof(fruit[0]);

    selectionSortString(fruit, n);

    for (int i = 0; i < n; i++)
    {
        cout << fruit[i] << " ";
    }

    return 0;
}