// 12) Without using && etc, find max as well as min out of 3 numbers. Same if should be
// used to find max as well as min. Aim to use minimum number of if statements.
#include<stdio.h>
int main(){
    int a,b,c;
     printf("Enter the three numbers: \n");
    scanf("%d %d %d" , &a, &b, &c );
    if (a>=b)
    {
        if (a>=c)
        {
            printf("The greatest number is : %d\n",a);
            if (b>=c)
            {
            printf("The smallest number is : %d\n",c);
            }
            else{
              printf("The smallest number is : %d\n",b);  
            }
            
        }
        else{
            printf("The greatest number is : %d\n",c);
            printf("The smallest number is : %d\n",b);
        }
        
    }
    else if (b>=c)
    {
            printf("The greatest number is : %d\n",b);
            if (a>=c)
            {
            printf("The smallest number is : %d\n",c);
            }
            else{
              printf("The smallest number is : %d\n",a);  
            }
    }
    else{
            printf("The greatest number is : %d\n",c);
            printf("The smallest number is : %d\n",a); 
    }
    
    return 0;
}