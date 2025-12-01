#include <iostream>
using namespace std;

// Function to 
void permutation(string &str, int i){
    // Base case
    if (i == str.size()){
        cout<<str<<endl;
        return;
    }
    // self work
    for (int j = i; j < str.size(); j++){
        swap(str[i], str[j]);
        permutation(str, i+1);
        swap(str[i], str[j]);
    }
}

int main() {
    string str = "ABC";
    permutation(str, 0);
    return 0;
}