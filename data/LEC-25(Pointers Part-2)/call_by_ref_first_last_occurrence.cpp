#include <bits/stdc++.h>
using namespace std;

// Find first and last occurrence of a character in a string
// using call by reference

// Method 1:
void findFirstAndLast(string str,char ch, int *first, int *last){
    int len = str.length();
    for(int i=0;i<len;i++){
        if(str[i]==ch){
            *first = i;
            break;
        }
    }
    for(int i=len-1;i>=0;i--){
        if(str[i]==ch){
            *last = i;
            break;
        }
    }
    
}

// Method 2:
// void findFirstAndLast(string str,char ch, int *first, int *last){
//     int len = str.length();
//     for(int i=0;i<len;i++){
//         if(str[i]==ch){
//             if(*first==-1)
//                 *first = i;
//             *last = i;
//         }
//     }
// }

int main()
{
    string str = "aaabac";
    char x = 'a';
    int first = -1, last = -1;

    findFirstAndLast(str, x, &first, &last);

    cout<<"First Occurrence = "<<first<<endl;
    cout<<"Last Occurrence = "<<last<<endl;
    return 0;
}