#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> input(n);

    for (int i = 0; i < n; i++){
        cin >> input[i];
    }

    map<int, int> m;
    for (int i = 0; i < n; i++){
        // storing frequency of every element in input array
        m[input[i]]++;
    }

    int sum = 0;
    // finding sum of repetative elements
    // pair - element, frequency
    for (auto pair : m){
        if (pair.second > 1)
            sum += pair.first;
    }

    cout << sum;
    return 0;
}