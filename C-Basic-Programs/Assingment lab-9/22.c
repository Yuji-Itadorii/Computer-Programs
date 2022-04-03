#include<stdio.h>
int main(){
    int a ;
    printf("Enter your marks: ");
    scanf("%d",&a);
    if (a>75)
    {
        printf("You pass with Honour");
    }
    else if(a>60)
    {
        printf("You pass with I division");
    }
    else if (a>45)
    {
        printf("You pass II division");
    }
    else if (a>30)
    {
        printf("You pass III division");
    }
    else if (a<30)
    {
        printf("You Fail");
    }
    
    
    return 0;
}