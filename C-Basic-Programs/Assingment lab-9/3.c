#include<stdio.h>
int main(){
    float salary , tax;
    printf("Enter Your salary : \n");
    scanf("%f",&salary);
    if (salary>100000)
    {
        tax = (salary*10)/100;
        printf("The tax amount is : %0.2f", tax);
    }
    else{
        printf("The tax amount is : %0.2f", 0);
    }
    
    return 0;
}