#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void counting_sort(int arr [] , int n , int exp){
    int count[10] ;
    int  output[n];
    for(int i = 0 ; i < 10 ; i++){
        count[i] = 0 ;
    }
    
    for(int i = 0 ; i < n ; i++){
        count[(arr[i]/exp)%10]++ ;
    }
    
    for(int i = 1 ; i < 10 ; i++){
        count[i] = count[i] + count[i-1] ;
    }

    for(int i = n-1 ; i>= 0 ; i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i = 0 ; i< n ; i++){
        arr[i] = output[i];
    }


}

void radix_sort(int arr[] , int n ){
   int mx = arr[0];
    for(int i = 1 ; i<n ; i++){
        if(arr[i] > mx){
            mx= arr[i];
        }
    }

    for(int exp = 1; (mx/exp)  > 0  ; exp = exp *10){
        counting_sort(arr , n , exp);
    }
}

int main(){
    int n = 7;
    int arr[] = {4 , 5, 6, 1 , 2, 3,8};

    radix_sort(arr , n);

    for(int x :arr){
        cout<<x<<" ";
    }


    return 0;
}