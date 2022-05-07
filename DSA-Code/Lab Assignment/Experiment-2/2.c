#include<stdio.h>
void swap_array(int arr1[] , int arr2[] , int size){
    for (int i = 0; i < size; i++)
    {
        int temp = arr1[i];
        arr1[i]=arr2[i];
        arr2[i] = temp;
    }
    
}
int main(){
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {6,7,8,9,10};
    printf("Array-1 : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    printf("Array-2 : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr2[i]);
    }

    swap_array(arr1 , arr2 , 5); 
    printf("\n After swapping\n");  

    printf("Array-1 : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    printf("Array-2 : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr2[i]);
    } 
    return 0;
}