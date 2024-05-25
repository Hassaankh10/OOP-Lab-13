#include<iostream>
using namespace std;
class A{
    public:
    int a,b;
};
istream &operator>>(istream &in, A &obj)
{
    in >> obj.a >> obj.b;
    return in;
}

ostream &operator<<(ostream &ou, const A &obj)
{
    ou << obj.a << " " << obj.b;
    return ou;
}
int main(){
A obj;
cin>>obj;
cout<<obj;
return 0;
}