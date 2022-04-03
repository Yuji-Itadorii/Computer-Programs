#include<stdio.h>
int main(){
    for (int i = 0; i <=5; i++)
    {
    int a =65;
        for (int j = 1; j <= 5-i; j++)
        {
           printf(" ");
        }
        for (int j = 1; j <=i; j++)
        {
           printf("%c",a);
           a++;
        }
        printf("\n");
    }
       
    return 0;
}