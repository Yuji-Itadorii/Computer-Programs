#include<stdio.h>
void swap_twoNumber(int * a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a = 2 , b= 3;
    printf("The value of a and b is %d and %d\n",a,b);
    swap_twoNumber(&a , &b);
    printf("The value of a and b is %d and %d\n",a,b);
    return 0;
}