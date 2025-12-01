#include <iostream>
using namespace std;

int main()
{
    cout << "Precedence and Associativity of Arithmetic Operators:" << endl; // all operators are left to right associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. ()" << endl;
    cout << "2. ++, --" << endl;
    cout << "3. *, /, %" << endl;
    cout << "4. +, -" << endl;
    cout << "5. =, +=, -=, *=, /=, %=" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Unary Operators:" << endl; // all operators are right to left associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. ++, --" << endl;
    cout << "2. +, -" << endl;
    cout << "3. !, ~" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Bitwise Operators:" << endl; // all operators are left to right associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. ~" << endl;
    cout << "2. <<, >>" << endl;
    cout << "3. &" << endl;
    cout << "4. ^" << endl;
    cout << "5. |" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Relational Operators:" << endl; // all operators are left to right associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. <, <=, >, >=" << endl;
    cout << "2. ==, !=" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Logical Operators:" << endl; // all operators are left to right associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. !" << endl;
    cout << "2. &&" << endl;
    cout << "3. ||" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Assignment Operators:" << endl; // all operators are right to left associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. =, +=, -=, *=, /=, %=" << endl;
    cout << "2. &=, ^=, |=, <<=, >>=" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Conditional Operators:" << endl; // all operators are right to left associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. ?: " << endl;
    cout << "---------------------------------------------------" << endl;

    cout<< "Precedence and Associativity of Comma Operator:" << endl // all operators are left to right associative
    << "---------------------------------------------------" << endl
    << "1. ," << endl
    << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of sizeof Operator:" << endl // all operators are right to left associative
    << "---------------------------------------------------" << endl
    << "1. sizeof" << endl
    << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Pointer Operators:" << endl; // all operators are right to left associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. *" << endl;
    cout << "2. &" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Member Selection Operators:" << endl; // all operators are left to right associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. ." << endl;
    cout << "2. ->" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Type Cast Operators:" << endl; // all operators are right to left associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. (type)" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Precedence and Associativity of Other Operators:" << endl; // all operators are left to right associative
    cout << "---------------------------------------------------" << endl;
    cout << "1. new, delete" << endl;
    cout << "2. new[], delete[]" << endl;
    cout << "3. typeid" << endl;
    cout << "4. const_cast" << endl;
    cout << "5. dynamic_cast" << endl;
    cout << "6. reinterpret_cast" << endl;
    cout << "7. static_cast" << endl;
    cout << "---------------------------------------------------" << endl;

// Precedence of all operators
    cout << "Precedence of all operators:" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "1. ()" << endl; // all operators are left to right associative
    cout << "2. ++, --" << endl; // all operators are right to left associative
    cout << "3. *, /, %" << endl; // all operators are left to right associative
    cout << "4. +, -" << endl; // all operators are left to right associative
    cout << "5. <<, >>" << endl; // all operators are left to right associative

    cout << "6. <, <=, >, >=" << endl; // all operators are left to right associative
    cout << "7. ==, !=" << endl; // all operators are left to right associative

    cout << "8. &" << endl; // all operators are left to right associative
    cout << "9. ^" << endl; // all operators are left to right associative 
    cout << "10. |" << endl; // all operators are left to right associative

    cout << "11. &&" << endl; // all operators are left to right associative
    cout << "12. ||" << endl; // all operators are left to right associative

    cout << "13. =, +=, -=, *=, /=, %=" << endl; // all operators are right to left associative
    cout << "14. &=, ^=, |=, <<=, >>=" << endl; // all operators are right to left associative

    cout << "15. ?: " << endl; // all operators are right to left associative

    cout << "16. ," << endl; // all operators are left to right associative

    cout << "17. sizeof" << endl; // all operators are right to left associative

    cout << "18. *" << endl; // all operators are right to left associative
    cout << "19. &" << endl; // all operators are right to left associative

    cout << "20. ." << endl; // all operators are left to right associative
    cout << "21. ->" << endl; // all operators are left to right associative

    cout << "22. (type)" << endl; // all operators are right to left associative

    cout << "23. new, delete" << endl; // all operators are left to right associative
    cout << "24. new[], delete[]" << endl; // all operators are left to right associative
    cout << "25. typeid" << endl; // all operators are left to right associative
    cout << "26. const_cast" << endl; // all operators are left to right associative
    cout << "27. dynamic_cast" << endl; // all operators are left to right associative
    cout << "28. reinterpret_cast" << endl; // all operators are left to right associative
    cout << "29. static_cast" << endl; // all operators are left to right associative
    cout << "---------------------------------------------------" << endl;

    return 0;


/*
// give me the precedence and associativity of different kind operators in C++:
// 1. Arithmetic Operators
// 2. Unary Operators
// 3. Bitwise Operators
// 4. Relational Operators
// 5. Logical Operators
// 6. Assignment Operators
// 7. Conditional Operators
// 8. Comma Operator
// 9. sizeof Operator
// 10. Pointer Operators
// 11. Member Selection Operators
// 12. Type Cast Operators
// 13. Other Operators
*/

/*Precedence and Associativity of Arithmetic Operators:
---------------------------------------------------
1. ()
2. ++, --
3. *, /, %
4. +, -
5. =, +=, -=, *=, /=, %=
---------------------------------------------------

Precedence and Associativity of Unary Operators:
---------------------------------------------------
1. ++, --
2. +, -
3. !, ~
---------------------------------------------------

Precedence and Associativity of Bitwise Operators:
---------------------------------------------------
1. ~
2. <<, >>
3. &
4. ^
5. |
---------------------------------------------------

Precedence and Associativity of Relational Operators:
---------------------------------------------------
1. <, <=, >, >=
2. ==, !=
---------------------------------------------------

Precedence and Associativity of Logical Operators:
---------------------------------------------------
1. !
2. &&
3. ||
---------------------------------------------------

Precedence and Associativity of Assignment Operators:
---------------------------------------------------
1. =, +=, -=, *=, /=, %=
2. &=, ^=, |=, <<=, >>=
---------------------------------------------------

Precedence and Associativity of Conditional Operators:
---------------------------------------------------
1. ?:
---------------------------------------------------

Precedence and Associativity of Comma Operator:
---------------------------------------------------
1. ,
---------------------------------------------------

Precedence and Associativity of sizeof Operator:
---------------------------------------------------
1. sizeof
---------------------------------------------------

Precedence and Associativity of Pointer Operators:
---------------------------------------------------
1. *
2. &
---------------------------------------------------

Precedence and Associativity of Member Selection Operators:
---------------------------------------------------
1. .
2. ->
---------------------------------------------------

Precedence and Associativity of Type Cast Operators:
---------------------------------------------------
1. (type)
---------------------------------------------------

Precedence and Associativity of Other Operators:
---------------------------------------------------
1. new, delete
2. new[], delete[]
3. typeid
4. const_cast
5. dynamic_cast
6. reinterpret_cast
7. static_cast
---------------------------------------------------
*/
    return 0;
}
