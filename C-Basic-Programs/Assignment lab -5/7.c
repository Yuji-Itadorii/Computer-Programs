#include<stdio.h>
int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum;
    printf("The sum of pair is : ");
    for (int i = 0; i < size/2; i++)
    {
        sum = 0;
        sum = sum + (arr[i]+arr[size-1-i]);
        printf("%d ", sum);
        (size%2!=0 && i == (size-2)/2)? printf("%d ", arr[i+1]*2) : printf("") ;
    } 
    return 0;
}