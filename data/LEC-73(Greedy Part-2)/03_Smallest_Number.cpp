#include<iostream>
#include<vector>
using namespace std;

// Function to find the smallest number with given sum of digits and number of digits
void smallestNumber(int s, int d){
    // If the sum is too large to be represented by d digits
    if(9*d < s){
        cout << -1 << endl;
        return;
    }

    // Initialize the number as a vector of digits
    vector<int> num(d, 0);

    /* Methode: 1 */
    // // Start from the last digit and distribute the sum
    // for(int i = d-1; i >= 0; i--){
    //     if(s > 9){
    //         num[i] = 9;
    //         s -= 9;
    //     } else {
    //         num[i] = s;
    //         s = 0;
    //     }
    // }
    // // Ensure the first digit is not zero
    // if(num[0] == 0){
    //     num[0] = 1;
    //     for(int i = 1; i < d; i++){
    //         if(num[i] > 0){
    //             num[i]--;
    //             break;
    //         }
    //     }
    // }

    /* Methode: 2 */
    s--;
    int i;
    for(i = d-1; i > 0; i--){
        if(s < 9) break;
        num[i] = 9;
        s -= 9;   
    }
    num[0] = 1;
    num[i] = s;

    // Print the number
    for(int i = 0; i < d; i++){
        cout << num[i];
    }
    cout << endl;
}

int main(){
    int s, d;
    cin >> s >> d;

    // Call the function to find the smallest number
    smallestNumber(s, d);
    return 0;
}