#include<iostream>
using namespace std;
void ParseData(){
    try{
    throw runtime_error("hello");
}
catch(runtime_error){
cout << "error in data "<< endl;
}
}
void processData(){
    ParseData();
}
int main(){
    processData();
return 0;
}
