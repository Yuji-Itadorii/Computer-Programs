#include<stdio.h>
int main(){
    int a;
    printf("Enter the year: \n");
    scanf("%d",&a);
    if (a<18)
    {
        printf("Not possible!");
    }
    else if (a>=18 && a<60)
    {
        printf("Possible!\n");
        printf("The lisence fee for male is : 1500\n");
        printf("The lisence fee for female is : 1000\n");
    } 
    return 0;
}