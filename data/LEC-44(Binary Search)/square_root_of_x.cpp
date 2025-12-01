#include <iostream>
#include <vector>
using namespace std;

// Using Linear Search(Brute Force Solution):
int linearSearch(int n, int x){
    int ans = -1;
    for (int i = 0; i <= n; i++){
        if (i * i <= x)
            ans = i;
        else
            break;
    }
    return ans;
}

// Using Binary Search: here we don't have any array, we are searching for the number x in the range [0, x]. This type of binary search is called "Decision Problem Binary Search" or "Binary Search on Answer"
int binarySearchSQRT(int low, int high, int x){
    int ans = -1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (mid * mid <= x){ // if mid*mid<=x, then we will check for the next greater number than mid.
            ans = mid;
            low = mid + 1;
        }
        else // if mid*mid>x, then we will check for the next smaller number than mid.
            high = mid - 1;
    }
    return ans;
}

int main()
{
    int x = 402;
    int low = 0;
    int high = x;

    cout << linearSearch(x, x) << endl;
    int ans = binarySearchSQRT(low, high, x);
    cout << ans << endl;
    return 0;
}