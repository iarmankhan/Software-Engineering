#include<stdio.h>
#include<stdbool.h>

bool isPrime(int n){
    bool prime[n+1];
    int i;
    for(i=0; i<=n; i++){
        prime[i] = true;
    } 
    // divisor < sqrt(n)
    for(int divisor = 2; divisor * divisor <= n; divisor++){
        if(prime[divisor]){
            for(i = 2*divisor; i<=n; i+=divisor){
                prime[i] = false;
            }
        }
    }

    for(i=2; i<=n; i++){
        if(prime[i]){
            printf(" %d", i);
        }
    }
}

void main(){
    isPrime(10);
}