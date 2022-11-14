#include<iostream>
#include<vector>
using namespace std;

void countingSort(int arr[] , int size , int k){
    vector<int> count(k , 0);
    for(int i = 0 ; i< size ; i++){
        count[arr[i]]++;
    }

    for(int i  = 1 ; i<k ; i++){
        count[i] = count[i] + count[i-1];
    }

    int output[size];

    for (int i = size-1; i>=0 ; i--)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
    
    

}

int main(){
    int arr[] = {6 ,4 ,2 ,1 , 1 ,3};
    int k = 10;

    countingSort(arr , 6 , k);

    for(int x : arr){
        cout<<x<<" ";
    }

    return 0;
}