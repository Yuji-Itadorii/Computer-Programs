#include<stdio.h>
int binarySearch(int arr[] , int size , int element){
    int s = 0 , e=size-1, mid ;
    while (s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]==element)
        {
           return mid; 
        }  
        else if (element>arr[mid])
        {
            s = mid+1;
        }
        else if (element<arr[mid])
        {
            e= mid-1;
        }    
    }
    return -1;
}
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int arr[size];   
    printf("enter the elements of array : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int element , check;
    printf("Enter the element of array : ");
    scanf("%d",&element);
    check = binarySearch(arr , size ,element);
    if (check!=(-1))
    {
        printf("The index of element is : %d\n",check);
    }
    else{
        printf("Element not found!!");
    }
    
    
    
    return 0;
}