#include<iostream>
using namespace std;
int removeDuplicate(int arr[] , int n){
    int res=1;
    for (int  i = 1; i < n; i++)
    {
        if (arr[i]!=arr[res-1])
        {
            arr[res] = arr[i];
            res++;
        }
        
    }
    return res;
}
int main(){
    int arr[]={1,2,2,3,3,4,5};
    int newSize =  removeDuplicate(arr , 7);
    for (int i = 0; i < newSize; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}