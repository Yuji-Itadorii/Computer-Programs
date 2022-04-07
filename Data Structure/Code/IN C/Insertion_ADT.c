#include<stdio.h>
void display(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
        printf("\n");
}

int sortedInsertion(int arr[] , int size , int element , int capacity , int index){
    if (size>=capacity)
    {
        return -1;
    }
    else{
        for (int i = size-1; i>=(index); i--)
        {
            arr[i+1] = arr[i];
        }
        arr[index]=element;
        return 1;
    }
}

int main(){
    int arr[100] = {1,2,3,4,5};
    int size = 5;
    display(arr , 5);  
    int element, index;
    printf("Enter the elment : "); 
    scanf("%d",&element);
    printf("Enter the index : "); 
    scanf("%d",&index);

    if (sortedInsertion(arr , size , element , 100 ,index) == 1)
    {
        printf("Enter the inserted array is  : ");
        size +=1;
        display(arr , size); 
    }
    else{
        printf("Error");
    }
    


    return 0;
}