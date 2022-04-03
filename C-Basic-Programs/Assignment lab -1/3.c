#include<stdio.h>
#include<conio.h>
int main(){
    int principal , rate , time ;
    float si ;
    printf("Enter the value of principal : ");
    scanf("%d",&principal);
    printf("Enter the value of rate : ");
    scanf("%d",&rate);
    printf("Enter the time : ");
    scanf("%d",&time);

    si = (principal*rate*time)/100;
    printf("The value of Simple intrest is  : %f", si);

    return 0 ;
}