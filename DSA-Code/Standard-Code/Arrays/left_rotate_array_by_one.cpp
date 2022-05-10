#include<iostream>
using namespace std;
void left_rotate(int arr[] , int size){
    int temp = arr[0];
    for (int i = 0; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[size-1] = temp;
}
int main(){
    int arr[] = {1,2,3,4,5}; 
    left_rotate(arr , 5);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}