#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    // Initialize String:
    // string str = "Jeet";
    // string str1("Majumdar");
    // cout<<str<<" "<<str1;

    // Input String:
    // string str2;
    // cin>>str2;  // It takes input upto space, tab or new line.
    // cout<<str2;
    // to get complete string we use getline method:
    // getline(cin, str2);
    // cout<<str2;

    // Indexing of Strings:
    // string str3 = "COLLEGE";
    // cout<<str3[0]<<endl;
    // cout<<str3[7]<<endl;    // null character = '\0'

    // ASCII Values:
    // cout<<int('A')<<" "<<int('Z')<<"\n";
    // cout<<int('a')<<" "<<int('z')<<"\n";

    // Character Array:
    char str4[20] = "Jeet Majumdar";
    for (int i = 0; i < 13; i++){
        cout<<str4[i];
    }
    
    return 0;
}