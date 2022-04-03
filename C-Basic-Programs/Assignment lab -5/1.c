#include<stdio.h>
int main(){
    int size , i;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int arr[size] , avrage =0;
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
        avrage = avrage + arr[i];
    }

    printf("The average is : %d",avrage/i);


       
    return 0;
}