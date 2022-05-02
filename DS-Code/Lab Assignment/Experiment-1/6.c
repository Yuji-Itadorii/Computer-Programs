#include<stdio.h>
#include<string.h>
char strndel(char str[] , int s , int e){
    int x = strlen(str);
    for (int i = s; i <strlen(str); i++)
    {   
        str[i]=str[i+(e-s)+1];
    }
    
}
int main(){
    char str[] = "1234567890" ;
    int s , e;
    scanf("%d %d",&s ,&e);
    strndel(str , s , e);
    printf("%s\n",str);
    
    return 0;
}