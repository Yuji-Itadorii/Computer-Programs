#include<iostream>
using namespace std;

void sortAscending(int *arr[]){
    
    for (int i = 0; i < 10-1; i++)
    {
        int min_ind = i ;
        for (int j = i+1; j < 10; j++)
        {
            if(*arr[min_ind]>*arr[j])
            min_ind=j;
        }
        swap(arr[min_ind],arr[i]);
    }
    
}

int main(){
    int arr[10];
    for(int i = 0 ; i< 10 ; i++){
        cin>>arr[i];
    }

    int * arr1[10] ;

    for (int i = 0; i < 10; i++)
    {
        arr1[i] = &arr[i];
    }

    sortAscending(arr1);

    for (int i = 0; i < 10; i++)
    {
        cout<<*arr1[i]<<" ";
    }
    
    return 0;
}