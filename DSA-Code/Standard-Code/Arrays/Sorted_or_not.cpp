#include<iostream>
using namespace std;
bool isSorted(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<arr[i-1])
        return false;
    }
    return true;
    
}
int main(){
    int arr[]={1,2,3,4,5};
    if(isSorted(arr,5)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}