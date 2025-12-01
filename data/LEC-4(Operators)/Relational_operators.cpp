#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout<<"Enter Two numbers: ";
    cin>>num1>>num2;

    cout<<"Is num1 is equals to num2: "<<(num1==num2)<<endl;
    cout<<"num1 is not equals to num2: "<<(num1!=num2)<<endl;
    cout<<"num1 greater than num2: "<<(num1>num2)<<endl;
    cout<<"num1 greater than or equals to num2: "<<(num1>=num2)<<endl;
    cout<<"num1 lesser than num2: "<<(num1<num2)<<endl;
    cout<<"num1 lesser than or equals to num2: "<<(num1<=num2)<<endl;
    return 0;
}



// By ChatGPT AI
// #include <iostream>

// int main()
// {
//     int num1, num2;
//     std::cout << "Enter two numbers: ";

//     // Input validation
//     if (!(std::cin >> num1 >> num2))
//     {
//         std::cout << "Invalid input." << std::endl;
//         return 1;
//     }

//     std::cout << "Is num1 equal to num2: " << (num1 == num2) << std::endl;
//     std::cout << "num1 is not equal to num2: " << (num1 != num2) << std::endl;
//     std::cout << "num1 greater than num2: " << (num1 > num2) << std::endl;
//     std::cout << "num1 greater than or equal to num2: " << (num1 >= num2) << std::endl;
//     std::cout << "num1 lesser than num2: " << (num1 < num2) << std::endl;
//     std::cout << "num1 lesser than or equal to num2: " << (num1 <= num2) << std::endl;

//     return 0;
// }
