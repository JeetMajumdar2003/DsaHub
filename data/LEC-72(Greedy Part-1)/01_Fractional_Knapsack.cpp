#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Item {
    public:
    int value;  // Value of the item
    int weight; // Weight of the item
};

// Comparison function to sort items by value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to get the maximum value in the knapsack
double fractionalKnapsack(int W, vector<Item>& arr) {
    // Sort items by value/weight ratio in descending order
    sort(arr.begin(), arr.end(), compare);

    int curWeight = 0;       // Current weight in knapsack
    double finalValue = 0.0; // Result (value in knapsack)

    // Loop through all items
    for (size_t i = 0; i < arr.size(); i++) {
        // If adding Item won't overflow, add it completely
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            // If we can't add current Item, add fractional part of it
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break; // Knapsack is full
        }
    }

    return finalValue; // Return the maximum value
}

int main(){
    int W;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    // Calculate and display the maximum value we can obtain
    cout<<"Maximum value we can obtain = "<<fractionalKnapsack(W, arr);
    return 0;
}