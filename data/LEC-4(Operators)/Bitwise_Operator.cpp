#include <iostream>
using namespace std;

int main()
{
    // short a = 32768, b = 8;
    int a = 5, b = 8, c = -7, d = -9;

    // Bitwise Complement Operator = 
    cout << "Bitwise Complement a = " << ~a << endl; // ~5 = -6 (2's complement of ~5)
    cout << "Bitwise Complement b = " << ~b << endl; // ~8 = -9 (2's complement of ~8)
    cout << "Bitwise Complement c = " << ~c << endl; // ~(-7) = 6 (2's complement of ~(-7))
    cout << "Bitwise Complement d = " << ~d << endl; // ~(-9) = 8 (2's complement of ~(-9))

/*
    1. For any integer n, the bitwise complement of n will be -(n+1).
    2. Bitwise complement of N = ~N (represented in 2’s complement form).
    3. 2’complement of ~N= -(~(~N)+1) = -(N+1).
*/
    // 2's Complement
    cout << "2's Complement of a = " << (~a + 1) << endl; // 2's Complement of 5 = -5 = -(~5 + 1) = -(~(0101)+1) = -(1010+1) = -(1011) = -11 wrong
    cout << "2's Complement of b = " << (~b + 1) << endl; // 2's Complement of 8 = -8 = -(~8 + 1) = -(~(1000)+1) = -(0111+1) = -(1000) = -8
    cout << "2's Complement of c = " << (~c + 1) << endl; // 2's Complement of -7 = 7 = -(~-7 + 1) = -(~(1001)+1) = -(0110+1) = -(0111) = -7 wrong
    cout << "2's Complement of d = " << (~d + 1) << endl; // 2's Complement of -9 = 9 = -(~(-9) + 1) = -(~(0111)+1) = -(1000+1) = -(1001) = -9 wrong

    // Bitwise AND Operator
    cout << "a & b = " << (a & b) << endl; // 5 & 8 = 0

    // Bitwise OR Operator
    cout << "a | b = " << (a | b) << endl; // 5 | 8 = 13

    // Bitwise XOR Operator
    cout << "a ^ b = " << (a ^ b) << endl; // 5 ^ 8 = 13

    // Bitwise Left Shift Operator
    cout << "a << 1 = " << (a << 1) << endl; // 5 << 1 = 20

    // Bitwise Right Shift Operator
    cout << "a >> 1 = " << (a >> 1) << endl; // 5 >> 1 = 1
    return 0;
}