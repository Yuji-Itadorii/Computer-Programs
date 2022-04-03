#include <stdio.h>
void patter( int n , char c){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%c",c);
        }
        for (int j = 0; j < i - 1; j++)
        {
            printf("%c",c);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    char c ;
    printf("Enter the value of n : \n");
    scanf("%d", &n);

    printf("Enter the character : \n");
    scanf(" %c", &c);


    patter(n , c);
    
    return 0;
}