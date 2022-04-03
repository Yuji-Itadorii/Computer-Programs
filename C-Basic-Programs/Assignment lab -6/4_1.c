#include<stdio.h>
#include<string.h>
int main(){
    int i ; 
    char s1[10] = {"Abhay"} , s2[10];
    printf("%s",s1);
    int x = strlen(s1);
    for ( i = 0; i < strlen(s1); i++)
    {
        s2[x-1] = s1[i];
        x--;
    }
    s2[strlen(s1)] = '\0';
    printf("%s",s2);
    
    return 0;
}