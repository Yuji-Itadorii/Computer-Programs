#include<stdio.h>
int main(){
    FILE * file ;
    file = fopen("file.txt" , "a");
    char str[20];
    scanf("%s",&str);
    fprintf(file , str);
    fclose(file);
    return 0;
}