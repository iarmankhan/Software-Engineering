#include<iostream>
using namespace std;

int main(){
    int n, i;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> n;

    for (i=2; i<=n; i++){
        if(n%i == 0){
            isPrime = false;
            break;
        }
    }

    if(isPrime){
        cout << "Prime number";
    }else{
        cout << "Not a prime number";
    }

    return 0;
}