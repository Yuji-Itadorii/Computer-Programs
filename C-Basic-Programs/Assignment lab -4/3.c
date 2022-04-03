#include<stdio.h>
int main(){
    int a , b, prev=0 , d;
    char oper;
    while (1)
    {   
        if(d==1){
            a=prev;
            printf("Your first number is : %d \n",a);
        }
        else{
        printf("Enter your first number: \n");
        scanf("%d", &a);
        }
        printf("Enter your operator number: \n");
        scanf(" %c", &oper);
        printf("Enter your second number: \n");
        scanf("%d", &b);
        switch (oper)
        {
        case '+': printf("The sum of the given number is : %d\n" ,a+b );
                prev =a+b;
            break;
        case '-': printf("The sum of the given number is : %d\n", a-b );
                prev =a-b;
            break;
        case '*': printf("The sum of the given number is : %d\n" ,a*b );
                prev =a*b;
            break;
        case '/': printf("The sum of the given number is : %0.2f\n" ,a/b );
                prev =a/b;
            break;
        default: printf("Enter the valid operator(+,-,*,/)");
            break;
        }
        int con ;
        printf("To continue enter 1 or to exit enter 0 : \n");
        scanf("%d" , &con );
        if (con==1)
        {
            printf("Use first number as previous result , enter 1 for yes or 0 for no:");
        scanf("%d",&d);
            continue ; 
        }
        else{
            break;
        }

        
        

    }
    
    return 0;
}