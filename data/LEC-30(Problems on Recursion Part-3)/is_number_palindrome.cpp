#include <iostream>
using namespace std;

bool f(int num, int *temp){
    // base case:
    if(num>=0 && num<=9){
        int lastDigitOfTemp = (*temp)%10;
        (*temp) /= 10;
        return (num == lastDigitOfTemp);
    }

    bool result = f(num/10, temp) and ((num%10) == ((*temp)%10));
    (*temp) /= 10;
    return result;
}

int main()
{
    int num = 12621;
    int anotherNum = num;
    int *temp = &anotherNum;
    cout<<f(num, temp);
    return 0;
}

/**
Initial state:
num = 12621
anotherNum = 12621
temp = &anotherNum
Call f(12621, temp)

First call to f:
f(12621, temp)
Check if num >= 0 and num <= 9 -> false
Call f(num/10, temp) -> f(1262, temp)
temp = 1
Compare num%10 (1) with *temp%10 (1) -> true
(*temp) /= 10;
result = true

Second call to f:
f(1262, temp)
Check if num >= 0 and num <= 9 -> false
Call f(num/10, temp) -> f(126, temp)
temp = 12
Compare num%10 (2) with *temp%10 (2) -> true
(*temp) /= 10;
result = true

Third call to f:
f(126, temp)
Check if num >= 0 and num <= 9 -> false
Call f(num/10, temp) -> f(12, temp)
temp = 126
Compare num%10 (6) with *temp%10 (6) -> true
(*temp) /= 10;
result = true

Fourth call to f:
f(12, temp)
Check if num >= 0 and num <= 9 -> false
Call f(num/10, temp) -> f(1, temp)
temp = 1262
Compare num%10 (2) with *temp%10 (2) -> true
(*temp) /= 10;
result = true

Fifth call to f:
f(1, temp)
Check if num >= 0 and num <= 9 -> true
temp = 12621
Compare num (1) with *temp%10 (1) -> true
(*temp) /= 10;
return true

Final state:
num = 12621
anotherNum = 1
temp = &anotherNum
cout << f(num, temp) -> cout << true -> print 1
*/