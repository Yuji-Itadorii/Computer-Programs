#include<iostream>
using namespace std;
int frequencyOfArray(int arr[] , int n){
    int i= 1 , freq = 1;
    while (i<n)
    {
        while (i<n && arr[i-1]==arr[i])
        {
            freq++;
            i++;
        }
        cout<<arr[i-1]<<" "<<freq<<endl;
        i++;
        freq = 1;
    }
    if (n==1 || arr[n-1]!=arr[n-2])
    {
        cout<<arr[n-1]<<" "<<1<<endl;
    }
}
int main(){
    int arr[] = {1,1,2,3,3,3}; 
    frequencyOfArray(arr , 6 );
    return 0;
}