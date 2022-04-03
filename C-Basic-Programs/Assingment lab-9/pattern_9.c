#include<stdio.h>
int main(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j <= 5-i; j++)
        {   
            if(i==0 && j==1){
                continue;
            }
            else{
            printf("*");
            }
        }
        for (int j = 1; j <=i; j++)
        {   
            if(j!=1){
            printf(" ");  
            }
        }
        for (int j = 1; j <=i; j++)
        {
            printf(" ");  
        }
        for (int j = 1; j <=5-i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
       
    return 0;
}