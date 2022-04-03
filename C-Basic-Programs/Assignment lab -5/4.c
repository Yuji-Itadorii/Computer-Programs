#include<stdio.h>
int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum_odd = 0 ,  sum_even = 0;
    for (int i = 0; i < size; i++)
    {
        if (i%2==0)
        {
            sum_odd =  sum_odd + arr[i];
        }
        else if (i%2!=0)
        {
            sum_even = sum_even + arr[i];
        }
    }

    // for (int i = 0; i < size; i++)
    // {
    //     if (i%2==0)
    //     {
    //         sum_odd =  sum_odd + arr[i];
    //     }
    // }

    // for (int i = 0; i < size; i++)
    // {
    //      if (i%2!=0)
    //     {
    //         sum_even = sum_even + arr[i];
    //     }
    // }

    printf("The sum of odd positioned element of array is :  %d \n", sum_odd);
    printf("The sum of even positioned element of array is :  %d ", sum_even);    
       
    return 0;
}