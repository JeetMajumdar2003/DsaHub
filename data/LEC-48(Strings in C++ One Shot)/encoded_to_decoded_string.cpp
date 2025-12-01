#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string decodeString(string encoded) {
    string decoded = "";
    // traverse the encoded string from left to right
    for (int i = 0; i < encoded.size(); i++){
        // insert the character into the decoded string, until we find a ']'(closing bracket)
        if (encoded[i] != ']'){
            decoded.push_back(encoded[i]); // or decoded += encoded[i];
        }
        // if we find a closing bracket, we need to decode the string
        else{
            // extract the string to be decoded, i.e. the string between the last '[' and the current ']' by traversing backwards and popping the characters from the decoded string until we find a '[' (opening bracket) or the decoded string is empty
            string str = "";
            while (decoded.back() != '[' && !decoded.empty()){   // decoded.back() returns the last character of the string
                str.push_back(decoded.back());
                decoded.pop_back();
            }
            // reverse the string to be decoded
            reverse(str.begin(), str.end());
            // remove the last character from the decoded string, that means remove the '['
            decoded.pop_back();
            // extract the number of times the string is to be repeated, i.e. the number before the '['
            string num = "";
            while (decoded.back() >= '0' && decoded.back() <= '9' && !decoded.empty()){
                num.push_back(decoded.back());
                decoded.pop_back();
            }
            // reverse the number to get the actual number if it is more than one digit
            reverse(num.begin(), num.end());
            // convert the string to be repeated to integer
            int n = stoi(num); // stoi() converts string to integer
            // repeat the string n times and insert it into the decoded string
            while (n--){
                decoded += str;
            }
        }
    }

    return decoded;
}

int main(){
    string encoded;
    cout << "Enter the encoded string: ";
    cin >> encoded;
    cout << decodeString(encoded) << endl;
    return 0;
}

