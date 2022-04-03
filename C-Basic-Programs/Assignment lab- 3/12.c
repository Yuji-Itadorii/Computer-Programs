#include<stdio.h>
int main(){
    int a , b , choice;
    char oper;
    while (1)
    {
        printf("Enter the First number : \n");
        scanf(" %d",&a);

        printf("Enter the operator  : \n");
        scanf(" %c",&oper);

        printf("Enter the Second number : \n");
        scanf(" %d",&b);

        if (oper=='+')
        {
        printf("The sum of the given number is  : %d\n",a+b);
        }
        else if (oper=='-')
        {
        printf("The substraction of the given number is  : %d\n",a-b);
        }
        else if (oper=='*')
        {
        printf("The multiplication of the given number is  : %d\n",a*b);
        }
        else if (oper=='/')
        {
        printf("The division of the given number is  : %0.2f\n",a/b);
        }

        printf("To continue enter 1 and to exit enter 0 : ");
        scanf("%d",&choice);
        if (choice==1)
        {
            continue;
        }
        else if (choice==0)
        {
            printf("Programme Exited");
            break;
        }      
    }
    
    
    
    return 0;
}