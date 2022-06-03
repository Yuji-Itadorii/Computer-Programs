#include<iostream>
using namespace std;

void reverseArray(int arr[], int size){
    int l = 0 , r=size-1;
    while (l<=r)
    {
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    reverseArray(arr,10);
    for(int i = 0; i<10 ; i++)
        cout<<arr[i]<<" ";
    return 0;
}