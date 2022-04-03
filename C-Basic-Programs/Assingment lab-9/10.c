#include<stdio.h>
int main(){
int a ;
printf("Enter the year: \n");
scanf("%d",&a);
    if (a%400==0)
    {
        printf("The year is a leap year !! \n");
    }
    else if (a%100==0)
    {
        printf("The year is not a leap year !! \n");
    }
    else if (a%4==0)
    {
        printf("The year is a leap year !! \n");
    }
    else{
        printf("The year is not a leap year !! \n");
    }
    
    
    
    return 0;
}