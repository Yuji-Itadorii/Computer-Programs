#include<iostream>
using namespace std;
int Binary_search(int arr[] , int n , int key){
    int s=0,e=n-1,mid;
    while (s<=e)
    {
        mid = (s+e) / 2 ;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        e=mid-1;
    else
        s=mid+1;
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5};
    cout<<Binary_search(arr,5 , 6);
    return 0;
}