#include<stdio.h>
#include<stdbool.h>

int isPrime(int n){
    int divisor = 2;
    while (divisor < n)
    {
        if(n % divisor == 0) {
            return false;
        }
        divisor++;
    }
    return true;
}

void main(){
    int n = 3;
    bool s = isPrime(n);

    if(s){
        printf("Prime number");
    }else{
        printf("Not a prime number");
    }
}

