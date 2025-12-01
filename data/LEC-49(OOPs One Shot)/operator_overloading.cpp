#include <iostream>
using namespace std;

class Complex {
    private:
        int real, imag;
    public:
        Complex(int r = 0, int i = 0) {
            real = r;
            imag = i;
        }

        Complex operator + (Complex const &obj) {
            Complex ans;
            ans.real = real + obj.real;
            ans.imag = imag + obj.imag;
            return ans;
        }

        void print() {
            cout << real << " + i" << imag << endl;
        }
};

int main() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
}
