#include<stdio.h>
int count ;
int linearSearch(int arr[] , int size , int key){
    for (int i = 0; i < 5; i++)
    {
        count++;
        if (arr[i]==key)
        {
            return i;
        }
        
    }
    return -1;
}
int main(){
    int arr[] = {1,4,7,3,9};
    int key = 7;
    printf("%d\n",linearSearch(arr , 5 , key));
    printf("The numer of comparisons are : %d\n",count);
    

    
    return 0;
}