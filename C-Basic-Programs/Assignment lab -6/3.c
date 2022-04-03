#include<stdio.h>
#include<string.h>
int main(){
    int i ; 
    char s1[10] = {"Abhay"} , s2[10];
    printf("%s",s1);
    for ( i = 0; i < strlen(s1); i++)
    {
        s2[i] = s1[i];
    }
    s2[i] = '\0';
    printf("%s",s2);
    
    return 0;
}