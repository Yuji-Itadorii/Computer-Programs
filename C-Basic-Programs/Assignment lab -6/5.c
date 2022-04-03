#include <stdio.h>
#include <string.h>
int main()
{
    int i ; 
    char s1[6] = {"Abhay"}, s2[6] = {"Rawat"}, s3[11];
    for ( i = 0; i < strlen(s1); i++)
    {
        s3[i] = s1[i];
    }
    for (int j = 0; j < strlen(s2); j++)
    {
        s3[i] = s2[j];
        i++;
    }
    printf("%s\n",s3);

    return 0;
}