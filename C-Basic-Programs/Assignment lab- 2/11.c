// 11) Using if-else, find max out of 3 distinct numbers. Use of && etc is not allowed.
#include<stdio.h>
int main(){
    int a,b,c;
     printf("Enter the three numbers: \n");
    scanf("%d %d %d" , &a, &b, &c );
    if (a>=b)
    {
        if (a>=c)
        {
            printf("The greatest number is : %d",a);
        }
        else{
            printf("The greatest number is : %d",c);
        }
        
    }
    else if (b>=c)
    {
            printf("The greatest number is : %d",b);
    }
    else{
            printf("The greatest number is : %d",c);
    }
    
    return 0;
}