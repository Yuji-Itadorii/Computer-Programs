#include<stdio.h>
int main(){
    int a ,d,n;
    printf("Enter the value of first term : \n");
    scanf("%d",&a);
    printf("Enter the value of common diffrence : \n");
    scanf("%d",&d);
    printf("Enter the n at which you want the series : ");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",a+(i-1)*d);
    }
    return 0;
}