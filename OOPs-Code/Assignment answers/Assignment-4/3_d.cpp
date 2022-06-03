#include<iostream>
using namespace std;

int count1 ;
int count2 ;
int count3 ;

void fill_matrix (int maxtrix[5][10], int size , int arr[]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            maxtrix[i][j] = arr[j + i*10];
            cout<<maxtrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


void bubbleSort( int size , int arr[] , int a[5][10] ){
    bool swapped = false;
    for (int i = 0; i < size-1; i++)
    {
        int count=0;
        for(int j = 0 ; j<size-1-i ; j++){
            if(arr[j]>arr[j+1]){
                count1++;
                count++;
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped==false)
            return;
        fill_matrix(a,50,arr);
        cout<<"The number of comaprison per excecution :- "<<count<<endl<<endl;
    } 
}

void selectionSort(int arr[] , int size , int a[5][10]){
    for (int i = 0; i < size-1; i++)
    {
        int count=0;
        int min_ind = i ;
        for (int j = i+1; j < size; j++)
        {
            if(arr[min_ind]>arr[j]){
            count2++;
            count++;
            min_ind=j;
            }
        }
        fill_matrix(a,50,arr);
        cout<<"The number of comaprison per excecution :- "<<count<<endl<<endl;
        swap(arr[min_ind],arr[i]);
    }
}

void insertionSort(int arr[] , int size , int a[5][10]){
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        int key =arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key)
        {
            count3++;
            count++;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        fill_matrix(a,50,arr);
        cout<<"The number of comaprison per excecution :- "<<count<<endl<<endl;
    }
    
}
int main(){

    int arr[] = {1,4,3,2,5,7,2,4,0,12,23,56,12,5,35,64,76,35,64,5,51,9,876,78,89,76,64,34,2,31,22,3,32,2,33,4,25,5567,787,8,89,7,6656,564,45,5,545,445,45,4};
    int maxtrix[5][10];
    // bubbleSort(50,arr,maxtrix);
    // cout<<"The number of comparison in bubbleSort is :- "<<count1<<endl;
    selectionSort(arr,50 , maxtrix);
    cout<<"The number of comparison in selectionSort is :- "<<count2<<endl;
    // insertionSort(arr,50 , maxtrix);
    // cout<<"The number of comparison in insertionSort is :- "<<count3<<endl;

    for(int i = 0 ; i<50 ;i++){
    cout<<arr[i]<<" ";
    }

    
    return 0;
}