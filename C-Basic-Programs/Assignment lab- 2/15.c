//  Print grades of a student A+/A/B/C/D/E using if-else ladder
#include<stdio.h>
int main(){
    int a ;
    printf("Enter your marks: ");
    scanf("%d",&a);
    if (a>=95)
    {
        printf("Your grade is A+");
    }
    else if(a<95 && a>=90)
    {
        printf("Your grade is A");
    }
    else if (a<90 && a>=80)
    {
        printf("Your grade is B");
    }
    else if (a<80 && a>=70)
    {
        printf("Your grade is C");
    }
    else if (a<70 && a>=60)
    {
        printf("Your grade is D");
    }
    else if (a<60)
    {
        printf("Your grade is E");
    }
    
    
    return 0;
}