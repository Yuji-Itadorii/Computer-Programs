#include<stdio.h>
void deletion(int arr[] , int size , int index){
    for (int i = index; i<size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    
}
int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    printf("Enter the element of array : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int index;
    printf("Enter the index no. : ");
    scanf("%d",&index);
    deletion(arr , size ,index);
    size--;
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}