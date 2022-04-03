#include<stdio.h>
int main(){
    int b =5;

    for (int i = 1; i <=5; i++) //Main for loop
    {
        int a=65;

        for (int j = 0; j <5-(i-1); j++)//for loop for first part
        {   
            if (j==4)
            {
                continue;
            }  
            printf("%c",a);
            a++;  
        }
//**************************************************************************************************
         int c=69;
         for(int j=1;j<i;j++)  
       {  
           if (j==1)
            {
                continue;
            }
            else{
           printf(" ");  
            } 
       }  
        for(int j=1;j<i;j++)  
       {  
           printf(" ");  
       }  
//**************************************************************************************************
       for(int k=1;k<=b;k++)  //for loop for second part
       {  
           printf("%c",c+(i-1));  
           c++;
       }  
       b--;
           
        printf("\n");
    }
    

    return 0;
}