#include<stdio.h>
#include<string.h>
int main(){
    char name[10] = {"AbhAy"};
    int count = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        int x = (int)name[i];
        if (x>=65  && x<=90)
        {
            count++;
        }
        
    }
    
    printf("%d",count);
    
    return 0;
}