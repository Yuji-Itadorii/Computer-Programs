#include<stdio.h>
#include<string.h>
void strfind(char str[] , char c){
    int j;
    for (int i = 0; i <strlen(str); i++)
    {
        if (str[i]==c)
        {
            for (j = i; j < strlen(str); j++)
            {
                str[j]=str[j+1];
            }
            return;
        }
        
    }
    
}
int main(){
    char str[] = "1234567890" ;
    char c;
    scanf("%c",&c);
    strfind(str ,c);
    printf("%s\n",str);
    
    return 0;
}