/** Question: Check if it is possible to survive on Island
 *  You are a poor person in an island. There is only one shop in this island, this shop is open on all days of the week except for Sunday. Consider 
 *  following constraints:
 *  S – Number of days you are required to survive.
 *  N – Maximum unit of food you can buy each day.
 *  M – Unit of food required each day to survive.
 *  Currently, it’s Monday, and you need to survive for the next S days.
 *  Find the minimum number of days on which you need to buy food from the shop so that you can survive the next S days, or determine that it isn’t possible 
 *  to survive.
 *  Example 1:
 *  Input: S = 10, N = 16, M = 2
 *  Output: Yes, 2
 *  Explanation: We can buy food on firstday(Monday) to survive for 8 days, and on 9th day(Tuesday) to survive for 2 more days i.e. total 10 days. But we
 *  should check we have enough food to survive for sunday as shop is closed on that day, otherwise we have to buy food on saturday also.
 */

#include <iostream>
#include <cmath>
using namespace std;

bool canSurvive(int S, int N, int M) {
    // // Calculate the number of Sundays in the given period
    // int sundays = S / 7;
    // // Calculate the number of days we can buy food
    // int buying_days = S - sundays;

    // // If the total food we can buy is less than the total food required, survival is not possible
    // if (buying_days * N < S * M) {
    //     return false;
    // }

    // // Calculate the minimum number of days required to buy food
    // int min_days_to_buy_food = ceil((double)S * M / N);

    // // Check if we can buy food on the required number of days
    // if (min_days_to_buy_food <= buying_days) {
    //     cout << "Minimum days to buy food: " << min_days_to_buy_food << endl;
    //     return true;
    // }

    // return false;

    // M-2

    if(((N * 6) < (M * 7) && S > 6) || M > N){
        return false;
    }
    else {
        cout << "Minimum days to buy food: " << ceil((double)S * M / N) << endl;
        return true;
    }

    return false;
}

int main() {
    int S, N, M;
    cin >> S >> N >> M;
    // Check if it is possible to survive with given constraints
    if(canSurvive(S, N, M)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}