#include<stdio.h>
int linearSearch(int arr[] , int size , int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        } 
    }
    return -1 ; 
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
    check = linearSearch(arr , size ,element);
    if (check!=(-1))
    {
        printf("The index of element is : %d\n",check);
    }
    else{
        printf("Element not found!!");
    }
    
    
    
    return 0;
}