#include<stdio.h>
int main(){
    int n;
    printf("Enter the value of n  : ");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {   
        for (int j = 0; j < n-i; j++)
        {
            printf(" ");
        }
        int a = 65;
        for (int j = 0; j < i; j++)
        {
            printf("%c",a);
            a++; 
        }

        for (int j = 0; j < i-1; j++)
        {
            printf("%c",a);
            a++;
        }
        printf("\n");
    }
       
    return 0;
}