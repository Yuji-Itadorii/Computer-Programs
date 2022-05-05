#include<iostream>
using namespace std;
void reverseArray(int arr[] , int n){
    int low = 0 , high = n-1;
    while (low<high)
    {
        int temp = arr[low];
        arr[low]=arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
    
    
}
int main(){
    int arr[]={1,2,3,4,5};
    reverseArray(arr , 5);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}