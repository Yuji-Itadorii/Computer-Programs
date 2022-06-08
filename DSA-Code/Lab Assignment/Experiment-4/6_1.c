#include<stdio.h>
int main(){
    FILE * file;
     file = fopen("file.txt" , "w");

     fprintf(file , "This is a new file");

     fclose(file);

    return 0;
}