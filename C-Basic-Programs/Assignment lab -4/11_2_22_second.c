//  8) Length is given in centimeters. Convert it into feets and inches
#include<stdio.h>
int main(){
    float a ;
    int  choice;
    printf("Enter the lenght in centimeters: \n");
    scanf("%f" , &a );
    printf("Enter your option \n Enter 1 for  In feet \n Enter 2 for in Inches \n");
    scanf("%d",&choice);
   
    switch (choice)
    {
    case 1 : printf("The lenght in feet is : %0.2f\n",a/30.48);
        break;
    case 2 :  printf("The lenght in inches is : %0.2f\n",a/2.54);
        break;
    default: printf("Please enter valid choice !");
        break;
    }
    
    return 0;
}