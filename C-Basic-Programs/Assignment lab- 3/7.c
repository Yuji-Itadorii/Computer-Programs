#include<stdio.h>
int main(){
    int num , sum = 0;
    do
    {
        num = 0;
        printf("Enter the number : \n");
        scanf("%d",&num);
        if (num==-1)
        {
            printf("Program exited!\n");
            break;
        }
        else{
        sum = sum + num ; 
        printf("The sum is : %d\n" , sum);
        }
    } while (1);    
    return 0;
}