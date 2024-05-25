#include<iostream>
using namespace std;

class Exception1: public exception {
public:
    const char* what() const noexcept override {
        return "exception1";
    }
};

class Exception2: public exception {
public:
    const char* what() const noexcept override {
        return "exception2";
    }
};

class Exception3: public exception {
public:
    const char* what() const noexcept override {
        return "exception3";
    }
};

void funcC() {
    throw Exception1();
}

void FuncB() {
    funcC();
}

void funcA() {
    FuncB();
}

int main() {
    try {
        funcA();
    }
    catch(Exception1 const &e) {
        cout << "Exception : " << e.what() << endl;
    }
    catch(...) {
        cout << "Exception occurred" << endl;
    }
    return 0;
}
