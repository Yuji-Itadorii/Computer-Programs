#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int element)
{
    int s = 0, e = size - 1, mid;
    while (s<=e)
    {
        mid = (s + e) / 2;
        if(arr[mid]==element)
        {
           return mid; 
        }  
        else if (element>arr[mid])
        {
            s = mid+1;
        }
        else if (element<arr[mid])
        {
            e= mid-1;
        }    
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size];
    cout << "Enter the element of array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int element, x;
    cout << "Enter the element which you want to find : " << endl;
    cin >> element;
    x = binarySearch(arr, size, element);
    if (x != (-1))
    {
        cout << "The element present at index no. : " << x;
    }
    else
    {
        cout << "Element not found !!";
    }
    return 0;
}