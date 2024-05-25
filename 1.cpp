#include<iostream>
using namespace std;
class A{
    int i;
    public:
    A(){
        i=0;
    }
    A(int a){
        i=a;
    }
};
class B:public A{
    int j;
    public:
    B(int a,int b):A(a){

        j=b;
    }
};
int main(){

return 0;
}