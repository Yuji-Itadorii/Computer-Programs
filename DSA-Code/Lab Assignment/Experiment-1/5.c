#include<stdio.h>
int main(){
    for (int i = 1; i <=5; i++)
    {
        for (int j = 1; j <=5-i; j++)
        {
            printf(" ");
        }
        int A = 65;
        for (int j = 1; j <=i; j++)
        {
            printf("%c",A);
            A++;
        }
        int B = 65;
        for (int j = 2; j <=i; j++)
        {

            printf("%c",B);
            B++;
        }
        
        printf("\n");




    }
    
    return 0;
}