#include<iostream>
using namespace std;

void maxHeapify(int arr[] , int size, int i){
    int l = 2*i +1 , r= 2*i +2;
    int largest = i;
    if(l<size && arr[l]>arr[largest]){
        largest = l;
    }
    else{
        largest = i;
    }

    if(r<size && arr[r]> arr[largest]){
        largest = r;
    }

    if(largest!=i){
        swap(arr[largest] , arr[i]);
        maxHeapify(arr , size , largest);
    }
}

void builHeap(int arr[] , int size){
    for(int i = (size-2)/2 ; i>=0 ; i--){
        maxHeapify(arr , size , i);
    }
}

void heapSort(int arr[] , int size){
    builHeap(arr , size);
    for(int i = size-1 ; i>=1 ; i--){
        swap(arr[0] , arr[i]);
        size = size -1;
        maxHeapify(arr , i , 0);
    }
}

int main(){
    int size;
    cout<<"Enter the size of array :- ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array :- "<<endl;
    for(int i = 0  ; i<size ; i++){
        cin>>arr[i];
    }

    heapSort(arr, size);

    for(int i = 0  ; i<size ; i++){
        cout<<arr[i]<<" ";
    }

    
    
    return 0;
}