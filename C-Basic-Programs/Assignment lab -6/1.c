#include <stdio.h>
#include<string.h>
int main()
{
    int i = 0;
    char s[25];
    printf("Enter a string --> ");
    scanf("%s",&s);
    printf("%s\n", s);
    printf("%d",strlen(s));
    return 0;
}
