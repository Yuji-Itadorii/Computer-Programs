#include<iostream>
using namespace std;

void display(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortedInsertion(int arr[] , int size ,int element ,int index , int capacity){
    if(size>=capacity){
        cout<<"Insertion not possible"<<endl;
    }
    else{
        for (int i = size-1; i >=index; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[index] = element;
        cout<<"Inserted Array is : "<<endl;
        display(arr , size+1);
    }
}

int main(){
    int arr[100] = {1,2,3,4,5};
    int size = 5 , element , index; 
    display(arr , size);
    cout<<"enter the element : ";
    cin>>element;
    cout<<"enter the index : ";
    cin>>index;  

    sortedInsertion(arr , size , element ,index , 100);

    return 0;
}