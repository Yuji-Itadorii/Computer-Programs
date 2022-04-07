#include<iostream>
using namespace std;

void deletion(int arr[] , int size , int index){
    for (int i = index; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
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
    int index;
    cout<<"Enter the index no. of which you want to delete the element : "<<endl;
    cin>>index;
    deletion(arr, size,index);
    size-=1;
    for(int i = 0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}