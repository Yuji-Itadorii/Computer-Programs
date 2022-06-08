#include<iostream>
using namespace std;

void sortAscending(int arr[] , int* ptr[] , int size){
    
    for (int i = 0; i < size; i++)
    {
        int min_ind = i ;
        for (int j = i+1; j < size; j++)
        {
            if(arr[min_ind]>arr[j])
            min_ind=j;
        }
        ptr[i] = &arr[min_ind];
    }
    
}

int main(){
    int arr[10];
    for(int i = 0 ; i< 10 ; i++){
        cin>>arr[i];
    }

    int * arr1[10] ;

    sortAscending(arr , arr1 , 10);

    for (int i = 0; i < 10; i++)
    {
        cout<<*(arr1[i])<<" ";
    }
    
    return 0;
}