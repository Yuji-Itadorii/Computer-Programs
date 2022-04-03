// Input 2 numbers (non-distinct). Using if-else, find which is bigger. Print EQUAL if
// they are equal
#include<stdio.h>
int main(){
    int a , b;
    printf("Enter the two number: \n");
    scanf("%d %d" , &a , &b);
    if (a>b)
    {
        printf("%d is bigger",a);
    }
    else if(a==b){
        printf("EQUAL");
    }
    else
    {
        printf("%d is bigger",b);
    }
    return 0;
}