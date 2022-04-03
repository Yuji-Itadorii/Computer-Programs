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
    for (int i = 0; i < size; i++)
    {
        sum = 0;
        if(size%2!=0 && i == size-1){
            sum = sum + (arr[i]*2);
        }
        else{
        sum = sum + (arr[i]+arr[i+1]);
        }
        printf("%d ", sum);
        i++;
        
    } 
    return 0;
}