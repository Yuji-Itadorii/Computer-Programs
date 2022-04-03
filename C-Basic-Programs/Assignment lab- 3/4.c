#include<stdio.h>
int main(){
    int n , sum = 0;
    printf("Enter thr value of n : ");
    scanf("%d",&n);
    for (int  i = 1; i <=n; i++)
    {
        sum = sum + (1+(i-1)*2);
    }
    printf("The value of sum of %d odd number is  : %d",n,sum);
    return 0;
}