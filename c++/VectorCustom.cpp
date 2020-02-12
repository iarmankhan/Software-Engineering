#include<iostream>

using namespace std;

class VectorClass {
    int* arr;

    int capacity;

    int current;

public:
    
    VectorClass()
    {
        arr = new int[1];
        capacity = 1;
        current = 0;
    }

    void push(int data)
    {
        if(current == capacity)
        {
            int* temp = new int[2 * capacity];

            for(int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }

            delete [] arr;

            capacity *= 2;
            arr = temp;
        }

        arr[current] = data;
        current++;
    }

    void push(int data, int index)
    {
        if(index == capacity)
            push(data);
        else
            arr[index] = data;
    }

    int get(int index)
    {
        if(index < current)
        {
            return arr[index];
        }
        return 0;
    }

    void pop()
    {
        current--;
    }

    int size()
    {
        return current;
    }

    int getcapacity()
    {
        return capacity;
    }

    void print()
    {
        for(int i = 0; i < current; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};


// Driver code 
int main() 
{ 
    VectorClass v; 
    v.push(10); 
    v.push(20); 
    v.push(30); 
    v.push(40); 
    v.push(50); 
  
    cout << "Vector size : "
         << v.size() << endl; 
    cout << "Vector capacity : "
         << v.getcapacity() << endl; 
  
    cout << "Vector elements : "; 
    v.print(); 
  
    v.push(100, 1); 
  
    cout << "\nAfter updating 1st index"
         << endl; 
  
    cout << "Vector elements : "; 
    v.print(); 
  
    cout << "Element at 1st index : "
         << v.get(1) << endl; 
  
    v.pop(); 
  
    cout << "\nAfter deleting last element"
         << endl; 
  
    cout << "Vector size : "
         << v.size() << endl; 
    cout << "Vector capacity : "
         << v.getcapacity() << endl; 
  
    cout << "Vector elements : "; 
    v.print(); 
  
    return 0; 
} 