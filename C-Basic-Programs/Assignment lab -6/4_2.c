#include<stdio.h>
#include<string.h>
int main(){
    int i ; 
    char s1[10] = {"Abhay"};
    printf("%s\n",s1);
    int x = strlen(s1);
    for ( i = 0; i <strlen(s1)/2; i++)
    {
        char temp = s1[i];
        s1[i] = s1[x-1];
        s1[x-1] = temp;
        x--;
    }
    printf("%s",s1);
    
    return 0;
}