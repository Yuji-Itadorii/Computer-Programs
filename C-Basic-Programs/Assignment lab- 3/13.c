#include<stdio.h>
#include<math.h>
int main(){
    int a , sum = 0 ;
    printf("Enter the number : \n");
    scanf("%d",&a);
    
    while(1)
    {
        if (a==0)
        {
            break;
        }
        int digit = 0;
        digit=(a%10);
        a=a-digit;
        a=a/10;
        sum = sum + digit;
        
        
    }
    printf("The sum of digits of the given number is : %d", sum);
    
    

    return 0;
}