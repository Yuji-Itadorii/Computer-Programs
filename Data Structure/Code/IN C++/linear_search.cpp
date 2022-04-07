#include<iostream>
using namespace std;

int linearSearch(int arr[] , int size , int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        }
        
    }
    return -1;
}

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter the element of array : "<<endl;
    for(int i = 0 ; i<size ; i++){
        cin>>arr[i];
    }
    int element , x;
    cout<<"Enter the element which you want to find : "<<endl;
    cin>>element;
    x = linearSearch(arr, size,element);
    if (x!=(-1) )
    {
        cout<<"The element present at index no. : "<<x;
    }
    else{
        cout<<"Element not found !!";
    }
    return 0;
}