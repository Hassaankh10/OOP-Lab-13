#include <iostream>
#include <string>
using namespace std;
template<typename T>
bool isPrime(T n) {
    if (n <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // n is divisible by i, hence not prime
        }
    }
    return true; // If no divisor is found, n is prime
} 
template<typename U>
class prime_generator{
    U *arr;
    int no;
    public:
    prime_generator(int n)no(n){
        int index=0;
        arr =new U[n];
        for(int i=1;i<n;i++){
            if(isPrime(i)){
                arr[index++]=i;
            }

        }
    }
friend bool idenfify_prime_sumofdigits;
void PrintRange(){
    for(int i=0;i<no;i++){
        cout<<arr[i];
    }
}

};
template <typename U>
U sumOfDigits(  U number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10; // Add the last digit to the sum
        number /= 10; // Remove the last digit from the number
    }
    return sum;
}
template <typename U>
bool identify_prime_sumofdigits(U number){
    U n=sumOfDigits(number);
    return isPrime(n);

}