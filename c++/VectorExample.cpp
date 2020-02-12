#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> q1;

    for (int i = 0; i <= 5; i++)
        q1.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = q1.begin(); i != q1.end(); ++i)
        cout << *i << " ";

    cout << "\nOutput of cbegin and cend: ";
    for (auto i = q1.cbegin(); i != q1.cend(); ++i)
        cout << *i << " ";

    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = q1.rbegin(); ir != q1.rend(); ++ir)
        cout << *ir << " ";

    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = q1.crbegin(); ir != q1.crend(); ++ir)
        cout << *ir << " ";

    cout << "\nSize: " <<  q1.size();
    cout << "\nCapacity: " <<  q1.capacity();
    cout << "\nMax_Size: " <<  q1.max_size();

    q1.resize(4);

    cout << "\nSize : " << q1.size();

    // checks if the vector is empty or not 
    if (q1.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 
  
    // Shrinks the vector 
    q1.shrink_to_fit(); 
    cout << "\nVector elements are: "; 
    for (auto it = q1.begin(); it != q1.end(); it++) 
        cout << *it << " "; 
  
    cout << "\n";

    return 0;
}