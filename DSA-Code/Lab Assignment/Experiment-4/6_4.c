#include<stdio.h>
#include<string.h>
int main(){
    FILE * file_pointer;
    file_pointer = fopen("file.txt" , "r");
    char str[255];
    
    while (fscanf(file_pointer , "%s" , &str)!=EOF)
    {
        if (strcmp(str, "This")==0)
        {
            printf("Yes!!\n");
            fclose(file_pointer);
            return 0 ;
        } 
    }
    printf("Not Found!!");
    
    fclose(file_pointer);
    return 0;
}