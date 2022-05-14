#include<stdio.h>
int count ;
void insertionSort(int arr[] , int size ){
    for (int i = 1; i < size; i++)
    {
        count++;
        int temp = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temp)
        {
            count++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
int main(){
    int arr[] = {1,3,5,6,2};
    insertionSort(arr , 5);
    for(int i = 0 ; i<5 ; i++)
    printf("%d ",arr[i]);
    printf("\nThe number of comparison are : %d", count);
    
    return 0;
}