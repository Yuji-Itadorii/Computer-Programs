#include<stdio.h>
int main(){
    int size , i;
    scanf("%d",&size);
    int arr[size];
    for (i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    for ( i = 0; i < size; i++)
    {
        if(arr[i]<0){
            printf("The index of first negative number is : %d \n ", i);
            break;
        }        
    }
    int sum = 0;
    for (int j = i+1; j < size; j++)
    {
        sum += arr[j];
    }
    printf("The sum of the array element onward negative term is : %d" , sum);
      
    return 0;
}