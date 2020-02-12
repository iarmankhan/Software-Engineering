#include <iostream>
using namespace std;

int main()
{
    int* a = NULL;
    int n;
    cout << "Enter limit =";
    cin >> n;
    a = new int[n];
    for(int i = 0; i< n; i++){
        a[i] = i;
    }

    for(int i = 0; i< n; i++){
        cout << a[i];
    }

    delete [] a;

    a = NULL;
}