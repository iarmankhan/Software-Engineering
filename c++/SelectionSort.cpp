#include <iostream>
using namespace std;



int main(){
    int arr[] = {4, 3, 6, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min_index, temp;
    for (int i = 0; i < n; i++){

        min_index = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }

        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp; 
    }

    for(int i =0; i < n; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;
}