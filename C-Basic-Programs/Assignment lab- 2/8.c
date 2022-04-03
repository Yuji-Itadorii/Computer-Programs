//  8) Length is given in centimeters. Convert it into feets and inches
#include<stdio.h>
int main(){
    float a , b , c;
    printf("Enter the lenght in centimeters: \n");
    scanf("%f" , &a );
    // cm in feet (divide the length value by 30.48)
    b=a/30.48;
    printf("The lenght in feet is : %0.2f\n",b);
    c=a/2.54;
    printf("The lenght in inches is : %0.2f\n",c);
    
    return 0;
}