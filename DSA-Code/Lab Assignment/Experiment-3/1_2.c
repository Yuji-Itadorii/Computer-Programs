#include<stdio.h>
int count ;
int binarySearch(int arr[] , int size , int key){
    int l = 0 , r = size-1;
     while (l <= r) {
        count++;
        int m = l + (r - l) / 2;
        if (arr[m] == key){ 
            return m;
        }

        if (arr[m] < key){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return -1;
    
}
int main(){
    int arr[] = {1,2,3,4,5};
    int key = 5;
    printf("%d\n",binarySearch(arr , 5 , key));
    printf("The number of comparison are : %d", count);
    
    return 0;
}