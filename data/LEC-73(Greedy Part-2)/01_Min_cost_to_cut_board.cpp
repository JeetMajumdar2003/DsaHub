#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long int

bool compare(int a, int b){
    return a > b;
}

// Function to find the minimum cost to cut a board of size n x m, [horizontal, vertical]
ll minCostToCutBoard(vector<ll> &vertical, vector<ll> &horizontal, int n, int m){
    // Sort the cost vectors in descending order
    sort(vertical.begin(), vertical.end(), compare);    // X
    sort(horizontal.begin(), horizontal.end(), compare);    // Y

    // initialize the number of horizontal and vertical boards
    int hz_blocks = 1, vt_blocks = 1;

    // initialize the cost vector index
    int hz_index = 0, vt_index = 0;

    // initialize the total cost
    ll total_cost = 0;

    // loop until, we have cut all the boards
    while(hz_index < n-1 and vt_index < m-1){
        // if the cost of cutting the horizontal board is less than the cost of cutting the vertical board
        if(horizontal[hz_index] > vertical[vt_index]){
            // add the cost of cutting the horizontal board to the total cost
            total_cost += horizontal[hz_index] * vt_blocks;
            // increment the number of horizontal blocks
            hz_blocks++;
            // move to the next horizontal board
            hz_index++;
        }
        // if the cost of cutting the vertical board is less than the cost of cutting the horizontal board
        else{
            // add the cost of cutting the vertical board to the total cost
            total_cost += vertical[vt_index] * hz_blocks;
            // increment the number of vertical blocks
            vt_blocks++;
            // move to the next vertical board
            vt_index++;
        }
    }

    // if there are still some horizontal boards left
    while(hz_index < n-1){
        // add the cost of cutting the horizontal board to the total cost
        total_cost += horizontal[hz_index] * vt_blocks;
        // increment the number of horizontal blocks
        hz_blocks++;
        // move to the next horizontal board
        hz_index++;
    }

    // if there are still some vertical boards left
    while(vt_index < m-1){
        // add the cost of cutting the vertical board to the total cost
        total_cost += vertical[vt_index] * hz_blocks;
        // increment the number of vertical blocks
        vt_blocks++;
        // move to the next vertical board
        vt_index++;
    }

    return total_cost;
}

int main(){
    // n -> number of horizontal boards
    // m -> number of vertical boards
    int n, m;
    cin >> n >> m;

    // vector to store the cost of cutting the horizontal boards
    vector<ll> horizontal(n-1);
    for(int i=0; i<n-1; i++){
        cin >> horizontal[i];
    }

    // vector to store the cost of cutting the vertical boards
    vector<ll> vertical(m-1);
    for(int i=0; i<m-1; i++){
        cin >> vertical[i];
    }

    // function call to find the minimum cost to cut the board
    cout << minCostToCutBoard(vertical, horizontal, n, m) << endl;

    return 0;
}

/**
 * Sample Input:
    4 6
    2 1 3
    4 1 2 3 1
 */