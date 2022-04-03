#include <stdio.h>
#include <string.h>
int main()
{
    int i ,j = 0; 
    char s1[12] = {"Abhay"}, s2[6] = {"Rawat"};
    const int z = strlen(s1);
    for ( i = strlen(s1); i < (strlen(s2)+strlen(s1)); i++)
    {
        s1[i]=s2[j];
        j++;
    }
    printf("%s\n",s1);

    return 0;
}