// 7) Convert time given in 24 hour format into 12 hour format.
#include<stdio.h>
int main(){
    float a;
    printf("Enter the time in 24 hour format: \n");
    scanf("%f" , &a );
    if (a>=12)
    {
    printf("The time in 12 hour format is : %0.2f\n",a-12);
    }
    else{
    printf("The time in 12 hour format is : %0.2f\n",a);

    }
    
    

    return 0;
}