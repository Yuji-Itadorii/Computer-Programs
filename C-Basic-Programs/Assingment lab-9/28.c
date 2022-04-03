#include<stdio.h>
int main(){
    int a, count=0;
    printf("Enter the number : ") ;
    scanf("%d",&a);
    if (a==2)
    {
        printf("Prime number\n") ;
    }
    else{
        for (int i = 2; i < a; i++)
        {   
            if (a%i==0)
            {
                printf("Not prime number\n");
                break;
            }
            else{
                count++;
            }
        }
    }
   
    if (count==a-2 && a!=2)
        {
                printf("Prime number");
        } 
    
     
    return 0;
}