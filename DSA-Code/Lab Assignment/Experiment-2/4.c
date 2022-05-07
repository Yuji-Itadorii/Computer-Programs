#include<stdio.h>
void swap_string(char**s1 , char ** s2){
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
int main(){
    char * s1 = {"Nit"};
    char * s2 = {"Kuruksetra"};
    swap_string(&s1 , &s2);
    printf("%s \n%s" , s1 , s2);

    return 0;
}