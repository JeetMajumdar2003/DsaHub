#include <iostream>
using namespace std;

// Polymorphism: same name, different parameters
// Function overloading: same function name, different parameters, different return type
class Sum{
    public:
        int add(int a, int b){
            return a + b;
        }
        int add(int a, int b, int c){
            return a + b + c;
        }
        double add(double a, double b){
            return a + b;
        }
};


int main() {
    Sum s;
    cout << s.add(1, 2) << endl;
    cout << s.add(1, 2, 3) << endl;
    cout << s.add(1.1, 2.2) << endl;
    return 0;
}
