#include<iostream>

// Standard Library Functions Header Files in C++
#include<cmath> // for mathematical functions
/*
#include<cstdlib>   // for mathematical functions
#include<ctime> // for time functions
#include<cstring>   // for string functions
#include<cctype>    // for character functions
#include<fstream>   // for file handling functions
#include<Windows.h> // for system functions
#include<conio.h>   // for system functions
#include<dos.h> // for system functions
#include<process.h>    // for system functions
#include<direct.h> // for system functions
#include<io.h>  // for system functions
#include<sys/stat.h>   // for system functions
#include<sys/types.h>  // for system functions
#include<sys/utime.h>  // for system functions
#include<sys/wait.h>   // for system functions
#include<sys/time.h>   // for system functions
#include<sys/resource.h>   // for system functions
#include<sys/ioctl.h>  // for system functions
#include<sys/termios.h>    // for system functions
#include<sys/filio.h>  // for system functions
*/
using namespace std;

int main(){
    // Mathematical Functions
    cout<< "power: "<< pow(2, 3)<<endl; // returns 2 raise to the power 3
    cout<< "square root: "<< sqrt(25)<<endl;    // returns square root of 25
    cout<< "round: "<< round(2.3)<<endl;    // returns integer value i.e. 2
    cout<< "floor: "<< floor(2.3)<<endl;   // returns gretaest integer value i.e. 2
    cout<< "ceil: "<< ceil(5.2)<<endl;  // returns smallest integer value i.e. 6
    cout<< "abs: "<< abs(-2.3)<<endl; // returns absolute value i.e. 2.3
    cout<< "fmax: "<< fmax(2.3, 3.4)<<endl; // returns maximum value i.e. 3.4
    cout<< "fmin: "<< fmin(2.3, 3.4)<<endl; // returns minimum value i.e. 2.3

/*
    // Random Number Functions
    srand(time(0)); // seed value for random number
    cout<< "Random Number: "<< rand()<<endl; // returns random number

    // String Functions
    char str1[20] = "Hello";
    char str2[20] = "World";
    cout<< "String Length: "<< strlen(str1)<<endl; // returns length of string
    cout<< "String Copy: "<< strcpy(str1, str2)<<endl; // copies str2 to str1
    cout<< "String Concatenation: "<< strcat(str1, str2)<<endl; // concatenates str2 to str1
    cout<< "String Compare: "<< strcmp(str1, str2)<<endl; // compares str1 and str2

    // Character Functions
    char ch = 'a';
    cout<< "isalpha: "<< isalpha(ch)<<endl; // returns true if ch is alphabet
    cout<< "isdigit: "<< isdigit(ch)<<endl; // returns true if ch is digit
    cout<< "islower: "<< islower(ch)<<endl; // returns true if ch is lowercase
    cout<< "isupper: "<< isupper(ch)<<endl; // returns true if ch is uppercase
    cout<< "tolower: "<< tolower(ch)<<endl; // converts ch to lowercase
    cout<< "toupper: "<< toupper(ch)<<endl; // converts ch to uppercase

    // File Handling Functions
    ofstream fout;  // output file stream
    fout.open("file.txt");  // open file
    fout<<"Hello World!";   // write to file
    fout.close();   // close file

    ifstream fin;   // input file stream
    fin.open("file.txt");   // open file
    char ch1;
    fin>>ch1;   // read from file
    cout<<ch1<<endl;
    fin.close();    // close file

    // System Functions
    system("cls");  // clear screen
    system("dir");  // list directory
    system("color 0a"); // change color of console
    system("pause");    // pause console
    system("shutdown -s");  // shutdown system
    system("shutdown -r");  // restart system
*/
    return 0;
}