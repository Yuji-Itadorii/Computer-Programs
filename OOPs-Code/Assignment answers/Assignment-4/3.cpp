#include<iostream>
using namespace std;

int count1 ;
int count2 ;
int count3 ;


void bubbleSort(int arr[] , int size){
    bool swapped = false;
    for (int i = 0; i < size-1; i++)
    {
        for(int j = 0 ; j<size-1-i ; j++){
            if(arr[j]>arr[j+1]){
                count1++;
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped==false)
            return;
    } 
}

void selectionSort(int arr[] , int size){
    for (int i = 0; i < size-1; i++)
    {
        int min_ind = i ;
        for (int j = i+1; j < size; j++)
        {
            if(arr[min_ind]>arr[j]){
            count2++;
            min_ind=j;
            }
        }
        swap(arr[min_ind],arr[i]);
    }
}

void insertionSort(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        int key =arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key)
        {
            count3++;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
}
int main(){

    int arr[] = {1,4,3,2,5,7,2,4,0,12,23,56,12,5,35,64,76,35,64,5,51,9,876,78,89,76,64,34,2,31,22,3,32,2,33,4,25,5567,787,8,89,7,6656,564,45,5,545,445,45,4};

    bubbleSort(arr,50);
    cout<<"The number of comparison in bubbleSort is :- "<<count1<<endl;
    // selectionSort(arr,50);
    // cout<<"The number of comparison in selectionSort is :- "<<count2<<endl;
    // insertionSort(arr,50);
    // cout<<"The number of comparison in insertionSort is :- "<<count3<<endl;

    for(int i = 0 ; i<50 ;i++){
    cout<<arr[i]<<" ";
    }

    
    return 0;
}