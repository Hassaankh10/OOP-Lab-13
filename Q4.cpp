#include<iostream>
using namespace std;

template<class F>
class D {
    F a;
public:
    D(F a): a(a) {
        if(a < 0) {
            throw 0;
        }
    }

    F factorial(F a) {
        if(a == 0) {
            return 1;
        }
        else {
            return a * factorial(a - 1);
        }
    }

    F getA() const {
        return a;
    }
};

int main() {
    try {
        D<int> obj(3);
        cout << "Factorial of " << obj.getA() << " is: " << obj.factorial(obj.getA()) << endl;
    }
    catch(int a) {
        cout << "Non-zero value entered." << endl;
    }

    return 0;
}
