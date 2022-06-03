#include<iostream>
using namespace std;

bool checkSame(int arr1[] , int arr2[], int size){
    for (int i = 0; i < size; i++)
    {
        if (arr1[i]!=arr2[i])
        {
            return false;
        }
        
    }
    return true;
    
}

int main(){
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
    if(checkSame(arr1,arr2,10)){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}