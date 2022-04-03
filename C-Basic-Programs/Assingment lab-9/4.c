#include<stdio.h>
int main(){
    int a,b;
    printf("Enter two number : \n");
    scanf("%d %d",&a , &b);
    (a>b)?printf("%d is grater than %d",a,b):printf("%d is grater than %d",b,a);
    return 0;
}