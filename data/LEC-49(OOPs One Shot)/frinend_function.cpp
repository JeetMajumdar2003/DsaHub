#include <iostream>
using namespace std;

class MyClass {
  private:
    int x;

  public:
    MyClass() {
        x = 0;
    }

    void setX(int val) {
        x = val;
    }

    friend void printX(MyClass obj);
};

void printX(MyClass obj) {
    cout << "The value of x is: " << obj.x << endl;
}

int main() {
    MyClass obj;
    printX(obj);
    obj.setX(5);
    printX(obj);
    return 0;
}
