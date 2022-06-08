#include<stdio.h>
int main(){
    FILE * file_pointer;
    file_pointer = fopen("file.txt" , "r");
    char str[255];
    
    while (fscanf(file_pointer , "%s" , &str)!=EOF)
    {
    printf("%s " ,str);
        
    }
    
    fclose(file_pointer);
    return 0;
}