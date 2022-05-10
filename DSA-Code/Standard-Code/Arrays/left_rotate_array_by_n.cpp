#include<iostream>
using namespace std;
void left_rotate(int arr[] , int size , int n){
    int temp[n];
    for (int i = 0; i < size; i++)
    temp[i] = arr[i];

    for (int i = n; i < size; i++)
    arr[i-n] = arr[i];
    
    for (int i = 0; i < n; i++)
    arr[size-n+i] = temp[i];
}
int main(){
    int arr[] = {1,2,3,4,5}; 
    left_rotate(arr , 5 , 2);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}