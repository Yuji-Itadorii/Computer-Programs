#include<stdio.h>
#include<string.h>
int main(){
    char name[50];
    int count = 0;
    scanf("%s",&name);
    for (int i = 0; i <strlen(name) ; i++)
    {
        if (name[i]=='A')
        {
            count++;
        }
        
    }
    printf("%d", count);
       
    return 0;
}