#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter limit: ";
    cin >> n;
    bool prime[n+1];

    for(int i=0; i<=n; i++){
        prime[i] = true;
    } 

    for(int divisor = 2; divisor * divisor <= n; divisor++){
        if(prime[divisor]){
            for(int i = 2 * divisor; i<=n; i+=divisor){
                prime[i] = false;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(prime[i]){
            cout << " " << i;
        }
    }

    return 0;
}   