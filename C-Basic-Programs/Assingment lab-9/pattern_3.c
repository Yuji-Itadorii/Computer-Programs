#include<stdio.h>
int main(){
    int a = 1;
    for (int i = 1; i <=5; i++)
    {
        for (int j = 1; j <=i; j++)
        {   
            if (a>9)
            {
                a = 0;
                printf("%d ", a);
                a++;
            }
            else{
            printf("%d ",a);
            a++;
            }
        }
        printf("\n");
    }
       
    return 0;
}