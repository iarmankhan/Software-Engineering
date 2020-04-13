#include <iostream>
using namespace std;

/* Driver code */
int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
