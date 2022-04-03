// 1) Input 2 distinct numbers . Using if (no else), show which is bigger.
#include<stdio.h>
int main(){
    int a , b;
    printf("Enter the two number: \n");
    scanf("%d %d" , &a , &b);
    if (a>b)
    {
        printf("%d is bigger",a);
    }
    if(b>a){
        printf("%d is bigger",b);
    }
    return 0;
}