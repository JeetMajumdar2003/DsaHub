#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 0; i < n; i++) // O(n^2)
    {
        for (int j = 0; j < sqrt(n); j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}

/**
 * Complexity Analysis:
 * i = 0, j = sqrt(n) instructions
 * i = 1, j = sqrt(n) instructions
 * i = 2, j = sqrt(n) instructions
 * i = 3, j = sqrt(n) instructions
 * i = 4, j = sqrt(n) instructions
 *  
 *  
 * i = n-1, j = sqrt(n) instructions
 *  
 * Total instructions = sqrt(n) * n 
 * worst case: O(n*sqrt(n)) = O(n^1.5)
*/